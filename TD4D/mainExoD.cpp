#include "SemaphoreCounterThread.h"
#include "Semaphore.h"


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

int semaphoreCount(unsigned nTokens, unsigned count)
{
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(nTokens, nTokens);
    SemaphoreCounterThread threadA(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadB(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadC(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadD(schedPolicy, count, &counter, &semaphore);
    
    struct timespec t1;
	struct timespec t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    threadA.start(8);
    threadB.start(8);
    threadC.start(8);
    threadD.start(8);
    
    threadA.join(8);
    threadB.join(8);
    threadC.join(8);
    threadD.join(8);

    clock_gettime(CLOCK_REALTIME, &t2);   
    
    printf("nTokens : %d, count : %d\n", nTokens, count);
    printTime(&t1, &t2);
    printf("compteur : %0.f\n", counter);
    
    return 0;
}

int main(int argc, char *argv[]) {
    semaphoreCount(1,1000);
    semaphoreCount(2,1000);
    semaphoreCount(3,1000);
    semaphoreCount(4,1000);
}
