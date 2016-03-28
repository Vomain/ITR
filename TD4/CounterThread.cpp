/** @file */

#include "CounterThread.h"

CounterThread::CounterThread(int schedPolicy, int nLoops, double *pCounter)
        : Thread(schedPolicy), nLoops(nLoops), pCounter(pCounter)
{
    /**
     * Thread incrémentant pCounter.
     * Classe héritant de Thread.
     */
}

void CounterThread::run() {
    /**
     * Incrémente nLoops fois pCounter.
     */
    for (int i = 0; i < nLoops; i++) {
        *pCounter += 1.0;
    }
}
