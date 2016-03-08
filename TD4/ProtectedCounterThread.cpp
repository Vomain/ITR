#include "ProtectedCounterThread.h"
#include "Lock.h"

ProtectedCounterThread::ProtectedCounterThread(int schedPolicy, int nLoops, double *pCounter, Mutex *mutex)
        : CounterThread(schedPolicy, nLoops, pCounter), mutex(mutex) { }

void ProtectedCounterThread::run() {
    for (int i = 0; i < nLoops; i++) {
        try {
            {
                printf("coucou  %d\n", i);
                Lock lock(mutex, 1000);
                *pCounter += 1.0;
            }
        }
        catch (Lock::TimeoutException const &e) {
            printf("Compteur : %f\n", *pCounter);
            printf(e.what());

        }
    }
}
