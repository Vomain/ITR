#include "Consumer.h"

Consumer::Consumer(int schedPolicy, int nLoops, Mutex *mutex, Fifo<int> *fifo) :
        CounterThread(schedPolicy, nLoops, pCounter), mutex(mutex), fifo(fifo) {

}

void Consumer::run() {

    for (int i = 0; i < nLoops; i++) {
        try {
            {
                printf("HOLA\n");
                Lock lock(mutex);
                printf("Je pop !\n");
                fifo->pop();
            }
        }
        catch (Lock::TimeoutException const &e) {
            printf("%s", e.what());
        }
    }

}