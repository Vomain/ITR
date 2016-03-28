#include "Chrono.h"
#include <stdio.h>
int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    //Sleep ?
    chrono1.stop();
    Timespec temps;
    printf("lolfd %f\n", chrono1.lap());
    printf("compteur : \n");

}