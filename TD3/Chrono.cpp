#include "Chrono.h"
#include <stdio.h>

Chrono::Chrono() {
    printf("chrono created\n");
    clock_gettime(CLOCK_REALTIME, &stopTime_);
    clock_gettime(CLOCK_REALTIME, &startTime_);
}

void Chrono::stop(){
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void Chrono::restart(){
    clock_gettime(CLOCK_REALTIME, &startTime_);
}
double Chrono::lap(){
    if (this->isActive()){ //stopTime_ < startTime_
        Timespec t_lap;
        clock_gettime(CLOCK_REALTIME, &t_lap);
        return (t_lap - startTime_).to_ms();
    }
    else{ // stopTime_ > startTime_ : le chrono est arreté
        return (stopTime_ - startTime_).to_ms();
    }

}

bool Chrono::isActive(){
    if (startTime_ < stopTime_){
        printf("loul\n");
        return true;
    }
    else{
        printf("lofdful\n");
        return false;
    }

}

