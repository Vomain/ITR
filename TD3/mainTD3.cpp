#include "Chrono.h"
#include "Sleeper.h"
#include <stdio.h>
#include <windows.h>
int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    Sleeper sleeper(30);

    sleeper.start(7);
    sleeper.join();

    chrono1.stop();
    Timespec temps;
    printf("lolfd %f\n", chrono1.lap());
    printf("compteur : \n");

}