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

int semaphoreCount(unsigned nThread, unsigned nTokens, unsigned count)
{
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(nTokens, nTokens);
    SemaphoreCounterThread table[nThread];
    
    for(int i = 0; i < nThread;i++)
    {
        SemaphoreCounterThread thread(schedPolicy, count, &counter, &semaphore);
        table[i] = thread;
    }
    
    struct timespec t1;
	struct timespec t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    for(int i = 0; i < nThread;i++)
    {
        table[i].start(8);
    }
    
    for(int i = 0; i < nThread;i++)
    {
        table[i].join();
    }
    
    clock_gettime(CLOCK_REALTIME, &t2);   
    
    printf("nThread : %d, nTokens : %d, count : %d", nThread, nTokens, count);
    printTime(&t1, &t2);
    printf("compteur : %0.f\n", counter);
    
    return 0;
}

int main(int argc, char *argv[]) {
    semaphoreCount(3,1,1000);
    semaphoreCount(3,2,1000);
    semaphoreCount(3,3,1000);
    
}
