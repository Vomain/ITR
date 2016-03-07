#include "Mutex.h"
#include <stdio.h>

Mutex::Mutex(bool isInversionSafe)
{
	pthread_mutex_init(&mid, NULL);
}

void Mutex::lock()
{
	pthread_mutex_lock(&mid);
}

void Mutex::lock(double timeout_ms)
{
	
}

bool Mutex::trylock()
{
	
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&mid);
}
	
