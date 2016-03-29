/** @file */

#include "Condition.h"
#include <stdio.h>
#include "Timespec.h"
#include <stdexcept>
#include "errno.h"

Condition::Condition() : Mutex(false) {
    pthread_cond_init(&cid, NULL);
}

Condition::Condition(bool isInversionSafe)
        : Mutex(isInversionSafe) {
    pthread_cond_init(&cid, NULL);
}

void Condition::wait() {
    int error = pthread_cond_wait(&cid, &mid);
    if(error == 1)
    {
        throw std::logic_error( "Le mutex de la condition n'est pas détenu par le thread courrant" );
    }
}

bool Condition::wait(double timeout_ms) {
    Timespec t1; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &t1); // Obtention du temps présent absolu

    Timespec t2;
    t2.from_ms(timeout_ms);

    t1 = t1 + t2;
    int error = pthread_cond_timedwait(&cid, &mid, &t1);
    return error != ETIMEDOUT;
}

void Condition::notify() {
    pthread_cond_signal(&cid);
}


void Condition::notifyAll() {
    pthread_cond_broadcast(&cid);
}

Condition::~Condition() {
    pthread_cond_destroy(&cid);
}

