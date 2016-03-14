#ifndef LOCK_H_INCLUDED
#define LOCK_H_INCLUDED

#include <pthread.h>
#include "Mutex.h"
#include <exception>

class Lock {

public:
    class TimeoutException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Timed out exception!\n";
        }

    private:
        int errorCode;
    };

public:
    Lock(Mutex *);

    Lock(Mutex *, double);

    ~Lock();

private:
    Mutex *mutex;
};

#endif
