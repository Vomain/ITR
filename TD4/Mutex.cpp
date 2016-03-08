#include "Mutex.h"
#include <stdio.h>

Mutex::Mutex(bool isInversionSafe)
{
	pthread_mutexattr_t mutexAttr;
	pthread_mutexattr_init(&mutexAttr);
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
	//todo set isInversionSafe
	pthread_mutex_init(&mid, &mutexAttr);
}

void Mutex::lock()
{
	pthread_mutex_lock(&mid);
}

bool Mutex::lock(double timeout_ms)
{
	printf("Lock mutex\n");
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t); // Obtention du temps présent absolu
	t.tv_nsec += timeout_ms*1000000; // Timeout des millisecondes
	t.tv_sec += t.tv_nsec / 1000000000; // Renormalisation des secondes
	t.tv_nsec = t.tv_nsec % 1000000000; // Renormalisation des nanosecondes	t.tv_sec += 1;

	int result = pthread_mutex_timedlock(&mid, &t);
	return result == 0;
}

bool Mutex::trylock()
{
	return pthread_mutex_trylock(&mid) == 0;
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&mid);
}
	
