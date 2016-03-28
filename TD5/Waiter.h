#ifndef WAITER_INCLUDED
#define WAITER_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class Waiter : public Thread {
public:
    Waiter(Semaphore *semaphore);

protected:
    void run();

private:
    Semaphore *semaphore;
};

#endif
