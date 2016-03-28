#include "SemaphoreCounterThread.h"
#include "Semaphore.h"


double semaphoreCount(unsigned nTokens, unsigned count)
{
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(nTokens, nTokens);
    SemaphoreCounterThread threadA(schedPolicy, count, &counter, &semaphore, 5);
    SemaphoreCounterThread threadB(schedPolicy, count, &counter, &semaphore, 5);
    SemaphoreCounterThread threadC(schedPolicy, count, &counter, &semaphore, 5);
    
    
    Timespec t1, t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    threadA.start(8);
    threadB.start(8);
    threadC.start(8);
    
    threadA.join(8);
    threadB.join(8);
    threadC.join(8);

    clock_gettime(CLOCK_REALTIME, &t2);   
    t2 = t2 - t1;
    printf("compteur : %f", counter);
    return t2.to_ms();
}

int main(int argc, char *argv[]) {
    semaphoreCount(1, 100);
    semaphoreCount(2, 100);
    semaphoreCount(3, 100);
}
