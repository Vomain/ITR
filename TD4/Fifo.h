#ifndef ITR_FIFO_H
#define ITR_FIFO_H

#include <queue>
#include <stdio.h>
#include "Condition.h"
#include "Lock.h"

template <typename T>
class Fifo {
public:
    Fifo() {};

    class EmptyException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Empty exception!\n";
        }

    private:
        int errorCode;
    };

    void push(T);

    // FIXME: pop ne retourne rien normalement. Erreur sur l'UML ? Sinon, on renvoie element.front() avant de pop
    // EDIT: c'est ce que j'ai fait au final
    T pop();

    T pop(double);
    
    void print();
    
    Condition *condition;
private:
    std::queue<T> elements;

};


#endif //ITR_FIFO_H
