/** @file */

#include "Mutex.h"
#include <stdexcept>

Mutex::Mutex(bool isInversionSafe) {
    /**
     * Appelle toutes les méthodes nécessaires à l'implémentation d'un mutex.
     */
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
    //todo set isInversionSafe
    pthread_mutex_init(&mid, &mutexAttr);
}

void Mutex::lock() {
    /**
     * Verrouille le mutex.
     */
    int error = pthread_mutex_lock(&mid);
    if(error != 0)
    {
        throw std::logic_error( "Le mutex ne peut pas être locked");
    }
}

bool Mutex::lock(double timeout_ms) {
    /**
     * Version avec timeout.
     */

    Timespec t1; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &t1); // Obtention du temps présent absolu

    Timespec t2;
    t2.from_ms(timeout_ms);

    t1 = t1 + t2;

    int result = pthread_mutex_timedlock(&mid, &t1); // Fonctionne avec un temps absolu
    return result == 0;
}

bool Mutex::trylock() {
    /**
     * Equivalent à Lock(), sauf en cas de mutex verrouillé.
     * Dans ce cas là, la méthode retourne immédiatement.
     */
    return pthread_mutex_trylock(&mid) == 0;
}

void Mutex::unlock() {
    /**
     * Déverrouille le mutex.
     */
    pthread_mutex_unlock(&mid);
}
	
