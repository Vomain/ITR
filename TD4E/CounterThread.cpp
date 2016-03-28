#include "CounterThread.h"

CounterThread::CounterThread(int schedPolicy, int nLoops, double *pCounter = NULL)
        : Thread(schedPolicy), nLoops(nLoops), pCounter(pCounter) { }

void CounterThread::run() {
    for (int i = 0; i < nLoops; i++) {
        *pCounter += 1.0;
    }
}
