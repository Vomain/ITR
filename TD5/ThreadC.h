#ifndef THREAD_C_INCLUDED
#define THREAD_C_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ThreadC : public Thread {
public:
    ThreadC(Semaphore *semaphore);

protected:
    void run();

private:
    Semaphore *semaphore;
};

#endif
