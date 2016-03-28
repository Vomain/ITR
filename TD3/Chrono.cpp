#include "Chrono.h"
#include <stdio.h>

Chrono::Chrono() {
    printf(stopTime_.to_ms());
    clock_gettime(CLOCK_REALTIME, &stopTime_);
    clock_gettime(CLOCK_REALTIME, &startTime_);
}

void stop(){
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void restart(){
    clock_gettime(CLOCK_REALTIME, &startTime_);
}
double lap(){

}

void isActive(){
    return &startTime_ < &stopTime_;
}

