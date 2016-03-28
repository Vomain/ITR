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

    threadA.start(8);
    threadB.start(8);
    threadC.start(8);

    printf("ncountThreads started!\n");

    threadA.join();
    threadB.join();
    threadC.join();

    printf("countThreads done!\n");

    printf("compteur : %0.f\n", counter);
    return 0;
}
