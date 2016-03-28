#include "Chrono.h"

int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    //Sleep ?
    chrono1.stop();
    Timespec temps;
    temps = chrono1.stopTime() - chrono1.startTime();
    printf("compteur : %0.f\n", temps.to_ms());

}