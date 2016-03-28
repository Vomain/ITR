#ifndef THREAD_A_INCLUDED
#define THREAD_A_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ThreadA : public Thread {
public:
    ThreadA(Semaphore *semaphore);

protected:
    void run();

private:
    Semaphore *semaphore;
};

#endif
