#include "Lock.h"
#include <stdio.h>

Lock::Lock(Mutex *m)
{
	m->lock();
}

Lock::Lock(Mutex *m, double timeout_ms)
{
	
}

class TimeoutException 
{
	
};
