#include "SemaphoreCounterThread.h"
#include "Semaphore.h"

SemaphoreCounterThread::SemaphoreCounterThread(int schedPolicy, int nLoops, double *pCounter, Semaphore *semaphore)
        : CounterThread(schedPolicy, nLoops, pCounter), semaphore(semaphore) { }

void SemaphoreCounterThread::run() {
    for (int i = 0; i < nLoops; i++) {
        semaphore->take();
        *pCounter += 1.0;
        sleep(10);
        semaphore->give();
    }
}
