#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

class Mutex
{
public:
	Mutex(bool isInversionSafe);
	void lock();
	void lock(double);
	bool trylock();
	void unlock();
private:
	pthread_mutex_t mid;
};

#endif
