#ifndef MUTEX_H_INCLUDED
#define MUTEX_H_INCLUDED

#include <pthread.h>
#include <stdio.h>
#include "Timespec.h"

class Mutex {
public:
    Mutex(bool isInversionSafe);

    void lock();

    bool lock(double);

    bool trylock();

    void unlock();

protected:
    pthread_mutex_t mid;
};

#endif
