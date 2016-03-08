#include "Lock.h"
#include <stdio.h>

Lock::Lock(Mutex *m)
{
	m->lock();
	mutex = m;
}

Lock::Lock(Mutex *m, double timeout_ms)
{
	
}

Lock::~Lock() 
{
	mutex->unlock();
}

class TimeoutException 
{
	
};
