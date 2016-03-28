#ifndef SEMAPHORE_COUNTER_THREAD_H
#define SEMAPHORE_COUNTER_THREAD_H

#include "CounterThread.h"
#include "Semaphore.h"

class SemaphoreCounterThread : public CounterThread {
public:
    SemaphoreCounterThread(int schedPolicy, int nLoops, double *pCounter, Sempahore *semaphore);

protected:
    void run();

private:
    Semaphore *semaphore;
};

#endif
