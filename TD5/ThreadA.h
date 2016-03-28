#ifndef THREAD_A_INCLUDED
#define THREAD_A_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ThreadA : public Thread {
public:
    ThreadA(Condition *condition);

protected:
    void run();

private:
    Condition *condition;
};

#endif
