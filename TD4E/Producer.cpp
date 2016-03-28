#include "Producer.h"

Producer::Producer(int schedPolicy, int nLoops) : Thread(schedPolicy) {

}

void Producer::run() {
    for (int i = 0; i < nLoops; i++) {
        fifo->push(i);
    }
}