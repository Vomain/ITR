#ifndef ITR_FIFO_H
#define ITR_FIFO_H

#include <queue>
#include "Condition.h"
#include <stdio.h>

class Fifo {
public:
    // On veut une FIFO de nombres entiers, on choisit donc T = int
    Fifo(std::queue<int>, class EmptyException);

    class EmptyException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Empty exception!\n";
        }

    private:
        int errorCode;
    };

    void push(int);

    // FIXME: pop ne retourne rien normalement. Erreur sur l'UML ? Sinon, on renvoie element.front() avant de pop
    int pop();

    int pop(double);

private:
    std::queue<int> elements;
    Condition condition;

};


#endif //ITR_FIFO_H
