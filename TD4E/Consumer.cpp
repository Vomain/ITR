#include "Consumer.h"

Consumer::Consumer(int schedPolicy, int nLoops, double *pCounter, Fifo<int> *fifo) :
        CounterThread(schedPolicy, nLoops, pCounter), fifo(fifo) {

}

char Consumer::bite() {

    for (int i = 0; i < nLoops; i++) {
        try {
            {
                printf("HOLA");
                Lock lock(fifo->condition);
                printf("Je pop !\n");
                fifo->pop();
            }
        }
        catch (Lock::TimeoutException const &e) {
            printf("%s", e.what());
        }
    }

}