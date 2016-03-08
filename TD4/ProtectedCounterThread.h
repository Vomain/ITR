#ifndef PROTECTED_COUNTER_THREAD_H
#define PROTECTED_COUNTER_THREAD_H

#include "CounterThread.h"
#include "Mutex.h"

class ProtectedCounterThread : public CounterThread {
public:
    ProtectedCounterThread(int schedPolicy, int nLoops, double *pCounter, Mutex *mutex);

protected:
    void run();

private:
    Mutex *mutex;
};

#endif
