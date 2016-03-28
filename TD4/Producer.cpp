#include "Producer.h"

Producer::Producer(int schedPolicy, int nLoops, Fifo<int> *fifo) : Thread(schedPolicy), fifo(fifo), nLoops(nLoops)
{}

void Producer::run() {
    for (int i = 0; i < nLoops; i++) {
        fifo->push(i);
    }
}