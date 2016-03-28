/** @file */

#include "SemaphoreCounterThread.h"
#include "Semaphore.h"
#include <stdio.h>

SemaphoreCounterThread::SemaphoreCounterThread(int schedPolicy, int nLoops, double *pCounter, Semaphore *semaphore, double timeout=0) : CounterThread(schedPolicy, nLoops, pCounter), semaphore(semaphore), timeout(timeout) 
{}

void SemaphoreCounterThread::run() {
    for (int i = 0; i < nLoops; i++) {
        if(timeout = 0){
            semaphore->take();
            *pCounter += 1.0;
            sleep(1);
            semaphore->give();
        } else {
            bool result = semaphore->take(timeout);
            if(result){
                *pCounter += 1.0;
                sleep(10);
                semaphore->give();
            }
        }
    }
}

