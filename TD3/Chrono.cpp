#include "Chrono.h"
Chrono::Chrono() {

}

void stop(){
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void restart(){
    clock_gettime(CLOCK_REALTIME, &startTime_);
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}

