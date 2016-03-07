#include "Mutex.h"
#include <stdio.h>

Mutex::Mutex(bool isInversionSafe)
{
	pthread_mutex_init(&mid);
}

void Mutex::lock()
{
	
}

void Mutex::lock(double timeout_ms)
{
	
}

bool Mutex::trylock()
{
	
}

void Mutex::unlock()
{
	
}
	
