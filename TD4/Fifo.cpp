#include "Fifo.h"

//template <typename T>
//Fifo::Fifo() {
////    elements;
////    condition;
//}

template <typename T>
void Fifo<T>::push(T element) {
    elements.push(element);
}

template <typename T>
T Fifo<T>::pop() {

    Lock lock(condition);
    if (elements.empty()) {

        throw EmptyException();
    }
    elements.pop();

    return elements.front();
}

template <typename T>
T Fifo<T>::pop(double timeout_ms) {

    try {
        {
            Lock lock(condition, timeout_ms);
        }
    }
    catch (Lock::TimeoutException const &e) {
        printf("%s", e.what());
    }

    if (elements.empty()) {

        throw EmptyException();
    }
    elements.pop();

    return elements.front();
}

template class Fifo<int>;
