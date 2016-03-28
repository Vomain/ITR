/** @file */

#include "Lock.h"

Lock::Lock(Mutex *m) {
    /**
     * La classe Lock gère le verrouillage d'un mutex, ainsi que sa libération.
     */
    m->lock();
    mutex = m;
}

Lock::Lock(Mutex *m, double timeout_ms) {
    /**
     * Version avec timeout.
     */
    mutex = m;
    if (!m->lock(timeout_ms)) {
        throw TimeoutException();
    }
}

Lock::~Lock() {
    /**
     * Le destructeur est appelé à chaque sortie de bloc, ce qui permet de déverrouiller implicitement le mutex.
     */
    mutex->unlock();
}
