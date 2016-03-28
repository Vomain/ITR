#include "Consumer.h"

Consumer::Consumer(int schedPolicy, int nLoops, Fifo<int> *fifo) : Thread(schedPolicy), fifo(fifo), nLoops(nLoops), compteur(0) 
{}

void Consumer::run() {
    for (int i = 0; i < nLoops; i++) {
        fifo->pop();
        compteur++;
    }
}