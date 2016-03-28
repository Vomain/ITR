#include "Fifo.h"

Fifo::Fifo(std::queue<int> elements, class EmptyException) : elements(elements) {
    condition.Condition();  // Chelou, "condition();" devrait suffire
}

void Fifo::push(int element) {
    elements.push(element);
}

int Fifo::pop() {
    elements.pop();
}

int Fifo::pop(double timeout_ms) {
    Timespec t1; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &t1); // Obtention du temps présent absolu

    Timespec t2;
    t2.from_ms(timeout_ms);

    Timespec t3;
    t3 = t1 + t2;

    if (!elements.empty()) {
        elements.pop();
    } else {
        throw EmptyException();
    }
}





