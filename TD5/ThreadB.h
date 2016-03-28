#ifndef THREAD_B_INCLUDED
#define THREAD_B_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ThreadB : public Thread {
public:
    ThreadB(Semaphore *semaphore);

protected:
    void run();

private:
    Semaphore *semaphore;
};

#endif
