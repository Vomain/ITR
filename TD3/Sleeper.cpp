#include "Sleeper.h"


Sleeper::Sleeper(int ms_to_wait): Thread(SCHED_RR), ms_to_wait(ms_to_wait)
{
    /**
     * Création d'un thread qui ne fait qu'attendre, pour les tests
     */
}

void Sleeper::run() {
    sleep(ms_to_wait);
}