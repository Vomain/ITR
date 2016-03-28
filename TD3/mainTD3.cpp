#include "Chrono.h"

int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    usleep(3000000);
    chrono1.stop();
    Timespec temps;
    temps = chrono1.stopTime() - chrono1.startTime();
    printf("compteur : %0.f\n", temps.to_ms());

}