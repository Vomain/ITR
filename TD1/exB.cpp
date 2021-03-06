#include "exB.h"

int main(int argc, char* argv[])
{
    unsigned int nLoops, nTasks;
    sscanf(argv[1], "%d", &nLoops);  // On prend le 1er argument donné en paramètre et on le convertit en int
    sscanf(argv[2], "%d", &nTasks);  // On prend le 2eme argument donné en paramètre et on le convertit en int

    pthread_t threads[nTasks];  // On crée un tableau de threads

    pthread_attr_t attr;  // On suit la routine de création de threads
    pthread_attr_init(&attr);  // Construction d’un attribut pthread
    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    sched_param schedParams;
    schedParams.sched_priority = 8; // Paramètres d’ordonnancement
    pthread_attr_setschedparam(&attr, &schedParams);

    struct timespec tDebut;
    struct timespec tFin;

    double counter = 0.0;
    struct arg_struct arg;  // Afin de passer un void* dans call_incr, une structure a été créée

    arg.nLoops = nLoops;
    arg.pCounter = &counter;

    clock_gettime(CLOCK_REALTIME, &tDebut);

    for (int i = 0; i < nTasks; i++)
    {
        pthread_create(&threads[i], &attr, call_incr, &arg);  // On crée nTasks threads
    }

    for (int i = 0; i < nTasks; i++)
    {
        pthread_join(threads[i], NULL);  // On n'oublie pas de join les threads une fois finies
    }

    clock_gettime(CLOCK_REALTIME, &tFin);

    printf("Le résultat final est : %lf\n", counter);
    printTime(&tDebut, &tFin);

    pthread_attr_destroy(&attr);  // Destruction d’un attribut pthread

    return 0;
}

void* call_incr(void *arg_pointer)
{
    /**
     * Appelle incr en lui passant les members du void* arg_pointer
     */
    arg_struct *argument = (arg_struct *) arg_pointer;
    incr(argument->nLoops, argument->pCounter);
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
