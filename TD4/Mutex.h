#ifndef MUTEX_H_INCLUDED
#define MUTEX_H_INCLUDED

#include <pthread.h>

class Mutex
{
public:
	Mutex(bool isInversionSafe);
	void lock();
	bool lock(double);
	bool trylock();
	void unlock();
private:
	pthread_mutex_t mid;
};

#endif
