#include "Fifo.h"

Fifo::Fifo(std::queue<int> elements) : elements(elements) {
    condition();
}


int Fifo::push() {
//    elements.push(5);
}

void Fifo::pop() {
//    elements.pop();
}

bool Fifo::pop(double timeout_ms) {
    return false;
}





