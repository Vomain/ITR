#ifndef SLEEPER_INCLUDED
#define SLEEPER_INCLUDED

#include "Thread.h"

class Sleeper : public Thread {
public:
    Sleeper(int ms_to_wait);

protected:
    void run();

private:
    int ms_to_wait;
};

#endif