#include "Semaphore.h"
#include "ThreadA.h"
#include "ThreadB.h"
#include "ThreadC.h"
#include "Timespec.h"
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {
    
    Semaphore semaphore(1,1);
    
    ThreadA threadA(&semaphore);
    ThreadB threadB(&semaphore);
    ThreadC threadC(&semaphore);
    
    Timespec t1, t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    threadC.start(7);
    std::chrono::milliseconds timespan(30);
    std::this_thread::sleep_for(timespan);
    threadA.start(9);
    threadB.start(8);
    
    
    
    threadA.join();
    clock_gettime(CLOCK_REALTIME, &t2);   
    
    threadB.join();
    threadC.join();

    t2 = t2 - t1;
    printf("Le thread A est terminé en %f ms", t2.to_ms());
}
