#ifndef WAITER_INCLUDED
#define WAITER_INCLUDED

#include "Thread.h"

class Waiter : public Thread {
public:
    Waiter();

protected:
    void run();

private:
    int seconds_to_wait;
};

#endif