#include "Mutex.h"
#include <stdexcept>

Mutex::Mutex(bool isInversionSafe) {
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
    //todo set isInversionSafe
    pthread_mutex_init(&mid, &mutexAttr);
}

void Mutex::lock() {
    int error = pthread_mutex_lock(&mid);
    if(error != 0)
    {
        printf("error n %d", error);
        throw std::logic_error( "Le mutex ne peut pas être locked");
    }
}

bool Mutex::lock(double timeout_ms) {
    Timespec t1; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &t1); // Obtention du temps présent absolu

    Timespec t2;
    t2.from_ms(timeout_ms);

    t1 = t1 + t2;

    int result = pthread_mutex_timedlock(&mid, &t1); // Fonctionne avec un temps absolu
    return result == 0;
}

bool Mutex::trylock() {
    return pthread_mutex_trylock(&mid) == 0;
}

void Mutex::unlock() {
    pthread_mutex_unlock(&mid);
}
	
