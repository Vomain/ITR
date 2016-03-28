#include "Sleeper.h"

/*
 * Création d'un thread qui ne fait qu'attendre, pour les tests
 */
Sleeper::Sleeper(int ms_to_wait): Thread(SCHED_RR), ms_to_wait(ms_to_wait)
{}

void Sleeper::run() {
    sleep(ms_to_wait);
}