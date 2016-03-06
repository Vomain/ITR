#include "exC.h"

int main(int argc, char* argv[])
{
	unsigned int nLoops, nTasks;
    sscanf(argv[1], "%d", &nLoops);  // On prend le 1er argument donné en paramètre et on le convertit en int
    sscanf(argv[2], "%d", &nTasks);  // On prend le 2eme argument donné en paramètre et on le convertit en int
	
	bool useMutex = false;

	if (argc > 3)  // Implémente la possibilité que le paramètre "mutex" soit optionnel
	{
		char *mutexString = (char *) "mutex";
		char *argMutex = argv[3];
		useMutex = strcmp(mutexString, argMutex) == 0;  // useMutex = 1 si mutexString == argMutex
	}
	
    pthread_t threads[nTasks];  // On crée un tableau de threads

    pthread_attr_t attr;  // On suit la routine de création de threads
	pthread_attr_init(&attr);  // Construction d’un attribut pthread
	pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
	sched_param schedParams;
	schedParams.sched_priority = 8; // Paramètres d’ordonnancement
	pthread_attr_setschedparam(&attr, &schedParams);	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);  // Nécessaire pour prendre en compte ce qui précède

	struct timespec tDebut;
	struct timespec tFin;

    double counter = 0.0;
    struct arg_struct arg;  // Afin de passer un void* dans call_incr, une structure a été créée

    arg.nLoops = nLoops;
    arg.pCounter = &counter;
    pthread_mutex_init(&arg.mutex, NULL);
    arg.useMutex = useMutex;

    clock_gettime(CLOCK_REALTIME, &tDebut);

    for(int i = 0;i<nTasks;i++)
	{
        pthread_create(&threads[i], &attr, call_incr, &arg);  // On crée nTasks threads
	}

	for (int i = 0; i < nTasks; i++)
	{
        pthread_join(threads[i], NULL);  // On n'oublie pas de join les threads une fois finies
	}

	clock_gettime(CLOCK_REALTIME, &tFin);

	printTime(&tDebut, &tFin);
    printf("Le résultat final est : %lf\n", counter);

	pthread_attr_destroy(&attr);  // Destruction d’un attribut pthread

	return 0;
}

void* call_incr(void *arg_pointer)
{
    /**
    * Appelle incr en lui passant les members du void* arg_pointer
    */
	arg_struct *argument = (arg_struct *) arg_pointer;

    if (argument->useMutex)
    {
		pthread_mutex_lock(&argument->mutex);  // Verrouillage du mutex (prise du jeton)
	}

	incr(argument->nLoops, argument->pCounter);

    if(argument->useMutex)
    {
		pthread_mutex_unlock(&argument->mutex);  // Déverrouillage du mutex (rendu du jeton)
	}
}

void incr(unsigned int nLoops, double* pCounter)
{
    /**
     * Incrémente pCounter nLoops fois
     */
    unsigned int i;
    for(i=0;i<nLoops;i++)
    {
        *pCounter += 1.0;
    }
}

void printTime(timespec *t2, timespec *t1)
{
    /**
     * Print la différence entre t1 et t2
     */
    float sec = t1->tv_sec - t2->tv_sec;
    float nsec = t1->tv_nsec - t2->tv_nsec;

    if(nsec < 0)  // Pour gérer le cas où le temps d'exécution serait supérieur à 1s
    {
        sec--;
        nsec = 1000000000-nsec;
    }

    float nsecDiff = fmod(nsec, 1000000000);
    float secDiff = (nsec - nsecDiff) / 1000000000 + sec;

    printf("Le temps total d'exécution est de : %.0f,%.0fs\n\n", secDiff, nsecDiff);
}

/*
 * 
 1 : 1
time diff : 1,763431424s

result : 10000000.000000



 1 : 2
time diff : 0,467593664s

result : 20000000.000000



 1 : 3
time diff : 1,296007168s

result : 30000000.000000



 1 : 4
time diff : 1,62641472s

result : 40000000.000000



 1 : 5
time diff : 1,174312064s

result : 50000000.000000



 1 : 6
time diff : 1,406830816s

result : 60000000.000000



 2 : 1
time diff : 1,527848320s

result : 20000000.000000



 2 : 2
time diff : 1,57298176s

result : 40000000.000000



 2 : 3
time diff : 1,400871552s

result : 60000000.000000



 2 : 4
time diff : 2,132412544s

result : 80000000.000000



 2 : 5
time diff : 2,346961088s

result : 100000000.000000



 2 : 6    hique (24 cas en tout) :
    nLoops ∈ {107, 2×107, 3×107, 4×107} et nTasks ∈ {1, 2, 3, 4, 5, 6}
    Que concluez-vous sur l’architecture processeur de votre cible ?

    Refaites ces mesures en configurant l’ordonnanceur de Linux en mode temps réel (SCHED_FIFO ou SCHED_RR, reportez-vous au cours).‎‎‎

Exécution sur plusieurs tâches avec mutex

Reportez-vous au cours pour l’utilisation des mutex Posix.

On rajoute un 3e argument mutex au programme correspondant à l’utilisation d’un mutex ou pas : si l’argument mutex est spécifié en ligne de commande, alors l’incrémentation de counter doit être protégée par un mutex, sinon, elle doit se faire sans protection (équivalent de la section précédente).


time diff : 3,180533120s

result : 120000000.000000



 3 : 1
time diff : 1,301211904s

result : 30000000.000000



 3 : 2
time diff : 1,409864352s

result : 60000000.000000



 3 : 3
time diff : 2,117445064s

result : 90000000.000000



 3 : 4
time diff : 3,175928960s

result : 120000000.000000



 3 : 5
time diff : 4,480651648s

result : 150000000.000000



 3 : 6
time diff : 4,233288672s

result : 180000000.000000



 4 : 1
time diff : 1,57513728s

result : 40000000.000000



 4 : 2
time diff : 2,123912448s

result : 80000000.000000



 4 : 3
time diff : 3,171802112s

result : 120000000.000000



 4 : 4
time diff : 3,765263872s

result : 160000000.000000



 4 : 5
time diff : 5,296777088s

result : 200000000.000000



 4 : 6
time diff : 6,340801664s

result : 240000000.000000
/ $ 

 * */
