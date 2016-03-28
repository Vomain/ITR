#include "Chrono.h"
#include <stdio.h>

Chrono::Chrono() {
    /**
     * On met stopTime légèrement avant pour être certains que isActive est vrai/
     */
    printf("Chrono created\n");
    clock_gettime(CLOCK_REALTIME, &stopTime_);
    clock_gettime(CLOCK_REALTIME, &startTime_);
}

void Chrono::stop(){
    /**
     * met stopTime après startTime, isActive() devient faux
     */
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void Chrono::restart(){
    /**
     * remet startTime après stopTime, isActive() devient vrai
     */
    clock_gettime(CLOCK_REALTIME, &startTime_);
}
double Chrono::lap(){
    if (this->isActive()) {   // stopTime_ < startTime_
        Timespec t_lap;
        clock_gettime(CLOCK_REALTIME, &t_lap);
        return (t_lap - startTime_).to_ms();
    }
    else {  // startTime_ <= stopTime_, le chrono est arrêté
        return (stopTime_ - startTime_).to_ms();
    }

}

bool Chrono::isActive(){
    if (startTime_ < stopTime_) { // stopTime est après donc le chrono a été arrêté
        return false;
    }
    else {
        return true;
    }

}

double startTime(){
    return startTime_.to_ms();
}
double stoptTime(){
    return stopTime_.to_ms();
}

