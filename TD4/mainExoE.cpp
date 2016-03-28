#include "Fifo.h"
#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[]) {
    printf("\nEXERCICE 5\n");

    int schedPolicy = SCHED_RR;
    printf("Start  !");

    Fifo<int> fifo;  // stack of ints
    printf("Start  !");

    Producer producer1(schedPolicy, 1000, &fifo);
    Producer producer2(schedPolicy, 2000, &fifo);
    Consumer consumer1(schedPolicy, 1000, &fifo);
    Consumer consumer2(schedPolicy, 1000, &fifo);
    Consumer consumer3(schedPolicy, 1000, &fifo);
    printf("Start  !");
    producer1.start(8);
    producer2.start(8);
    consumer1.start(8);
    consumer2.start(8);
    consumer3.start(8);
    printf("Join !");
    producer1.join(8, 1000.0);
    producer2.join(8, 1000.0);
    consumer1.join(8, 1000.0);
    consumer2.join(8, 1000.0);
    consumer3.join(8, 1000.0);
    
    printf("Terminé !");
    printf("Compteurs : \n   1 : %d, \n   2 : %d, \n   3 : %d\n", consumer1.compteur, consumer2.compteur, consumer3.compteur);
        
    return 0;
}


