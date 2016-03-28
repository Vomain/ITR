#ifndef SLEEPER_INCLUDED
#define SLEEPER_INCLUDED

#include "Thread.h"

/*
 * Création d'un thread qui ne fait qu'attendre, pour les tests
 */

class Sleeper : public Thread {
public:
    Sleeper(int ms_to_wait);

protected:
    void run();

private:
    int ms_to_wait;
};

#endif