#include "ProtectedCounterThread.h"
#include "Fifo.h"
#include "Consumer.h"

int main(int argc, char *argv[]) {
    /**
    * C'est ici que nous lançons notre main
    */

    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    printf("C'est bon, j'ai réussi à compiler !\n");

    Fifo<int> fifo;  // stack of ints
    Mutex mutex(true);

    int n = 10;

    for (int i = 0; i < n; i++)
    {
        printf("Je push !\n");
        fifo.push(666);
    }

    Consumer consumer(schedPolicy, 10, &mutex, &fifo);

    consumer.start(8);
    printf("J'ai créé consumer \n");

    for (int i = 0; i < 100; i++) {
        printf("Je rentre dans la boucle\n");
        consumer.run();
//        char * result = (char *) consumer.run();
        printf("ICI C'EST LA BOUCLE\n");
//        printf("%s\n",  result);
    }

//    ProtectedCounterThread counterThreadA(schedPolicy, 10, &counter, &mutex);
//    Mutex mutex(true);
//
//    printf("countThread created!\n");
//
//    counterThreadA.start(8);
//    counterThreadA.start(8);
//
//    printf("ncountThreads started!\n");
//
//    counterThreadA.join();
//    counterThreadA.join();
//
//    printf("countThreads done!\n");
//
//    printf("compteur : %0.f\n", counter);
    return 0;
}


