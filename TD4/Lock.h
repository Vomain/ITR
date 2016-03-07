#ifndef LOCK_H
#define LOCK_H

#include <pthread.h>
#include "Mutex.h"

class Lock
{
public:
	Lock(Mutex*);
	Lock(Mutex*, double);
	class TimeoutException;
};

#endif
