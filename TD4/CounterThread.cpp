#include "CounterThread.h"
#include <stdio.h>

CounterThread::CounterThread(int schedPolicy, int nLoops, double *pCounter)
        : Thread(schedPolicy), nLoops(nLoops), pCounter(pCounter) { }

void CounterThread::run() {
    printf("RUN from counter Thread");
    for (int i = 0; i < nLoops; i++) {
        *pCounter += 1.0;
    }
}
