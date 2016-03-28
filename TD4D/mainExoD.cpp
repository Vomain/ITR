#include "SemaphoreCounterThread.h"
#include "Semaphore.h"

int main(int argc, char *argv[]) {
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(3,3);
    SemaphoreCounterThread threadA(schedPolicy, 1000, &counter, &semaphore);
    SemaphoreCounterThread threadB(schedPolicy, 1000, &counter, &semaphore);
    SemaphoreCounterThread threadC(schedPolicy, 1000, &counter, &semaphore);
    
    printf("semaphore using counterThreads created!\n");
    
    Timespec t1;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    threadA.start(8);
    threadB.start(8);
    threadC.start(8);

    printf("ncountThreads started!\n");

    threadA.join();
    threadB.join();
    threadC.join();

    Timespec t2;
    clock_gettime(CLOCK_REALTIME, &t2);    
    
    printTime(&t1, &t2);

    printf("compteur : %0.f\n", counter);
    return 0;
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