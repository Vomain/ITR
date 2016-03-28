#include "Semaphore.h"
#include "Lock.h"

unsigned UINT_MAX = 1000;

Semaphore::Semaphore(unsigned counter = 0, unsigned maxCount = UINT_MAX) : counter(counter), maxCount(maxCount), condition()
{}


/*
    Rend un jeton au sémaphore, si on n'atteint pas le maximum.
    Quand le compteur est incrémenté, un des threads en attente est notifié
*/

void Semaphore::give() {
    Lock lock(&condition); //Protège la variable counter
    if (counter < maxCount) {
        counter++;
        condition.notify();
    }
}

/*
    Notifie tous les thread en attente de la condition
*/

void Semaphore::flush() {
    condition.notifyAll();
}

/*
    Prend un jeton au sémaphore
    S'il n'y a plus de jeton, l'appel est bloquant et le thread est mis en pause par la condition.
    A l'arrivée d'un signal ou d'un broadcast, la condition est testée à nouveau.
*/

void Semaphore::take() {
    Lock lock(&condition);
    if (counter == 0) {
        while (counter == 0) {
            condition.wait();
        }
    } else {
        counter--;
    }
}

/*
    Idem, avec un timeout sur le temps de lock
*/

bool Semaphore::take(double timeout_ms) {
    Timespec tmax; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &tmax);

    Timespec t_timeout;
    t_timeout.from_ms(timeout_ms);

    // tmax devient l'échéance à ne pas dépasser
    tmax = tmax + t_timeout;

    Lock lock(&condition);
    if (counter == 0) {
        while (counter == 0) {
            Timespec tmaxWait;
            clock_gettime(CLOCK_REALTIME, &tmaxWait);
            
            if(tmax < tmaxWait){ // si échéance est avant le temps actuel
                return false;
            } else {
                tmaxWait = tmax - tmaxWait; // délai encore disponible
                double timeout = tmaxWait.to_ms();
                bool result = condition.wait(timeout);
                if (!result) { // si c'est un timeout qui a libéré le thread
                    return false;
                }
            }
        }

    }
    counter--;
    return true;
}