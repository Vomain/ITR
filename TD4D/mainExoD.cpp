#include "SemaphoreCounterThread.h"
#include "Semaphore.h"

int main(int argc, char *argv[]) {
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(2,2);
    
    SemaphoreCounterThread threadA(schedPolicy, 10, &counter, &semaphore);
    SemaphoreCounterThread threadB(schedPolicy, 10, &counter, &semaphore);
    SemaphoreCounterThread threadC(schedPolicy, 10, &counter, &semaphore);
    
    printf("semaphore using counterThreads created!\n");

    counterThreadA.start(8);
    counterThreadB.start(8);
    counterThreadC.start(8);

    printf("ncountThreads started!\n");

    counterThreadA.join();
    counterThreadB.join();
    counterThreadC.join();

    printf("countThreads done!\n");

    printf("compteur : %0.f\n", counter);
    return 0;
}
