#include "exA.h"
	
int main(int argc, char* argv[])
{
	unsigned int nLoops;
	sscanf(argv[1], "%d", &nLoops);  // On prend le 1er argument donné en paramètre et on le convertit en int

    double counter = 0.0;

    struct timespec tDebut;
    struct timespec tFin;

    clock_gettime(CLOCK_REALTIME, &tDebut);
    incr(nLoops, &counter);
    clock_gettime(CLOCK_REALTIME, &tFin);

    printf("La valeur finale de counter est : %lf\n", counter);
    printTime(&tDebut, &tFin);


	return 0;
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

    if (nsec < 0)  // Pour gérer le cas où le temps d'exécution serait supérieur à 1s
	{
		sec--;
		nsec = 1000000000-nsec;
	}

	float nsecDiff = fmod(nsec, 1000000000);
	float secDiff = (nsec - nsecDiff) / 1000000000 + sec;

	printf("La différence de temps est de : %.0f,%.0fs\n", secDiff, nsecDiff);
}
