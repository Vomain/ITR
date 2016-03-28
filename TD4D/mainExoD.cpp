#include "SemaphoreCounterThread.h"
#include "Semaphore.h"


double semaphoreCount(unsigned nTokens, unsigned count)
{
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Semaphore semaphore(nTokens, nTokens);
    SemaphoreCounterThread threadA(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadB(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadC(schedPolicy, count, &counter, &semaphore);
    SemaphoreCounterThread threadD(schedPolicy, count, &counter, &semaphore);
    
    Timespec t1, t2;
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
    t2 = t2 - t1;
    return t2.to_ms();
}

int main(int argc, char *argv[]) {
    for(int nToken = 1; nToken < 5; nToken ++){
        printf("NTOKEN = %d\n", nToken);
        double mean = 0.0;
        for(int i = 0 ; i < 5; i++){
            double time = semaphoreCount(nToken,1000);
            printf("        time : %f\n", time);
            mean += time / 5;
        }
        printf("        Mean time for nToken=%d : %f\n", nToken,mean);
    }
}
