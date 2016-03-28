#include "Lock.h"
#include <stdio.h>

Lock::Lock(Mutex *m) {
    m->lock();
    mutex = m;
}

Lock::Lock(Mutex *m, double timeout_ms) {
    mutex = m;
    if (!m->lock(timeout_ms)) {
        throw TimeoutException();
    }
}

Lock::~Lock() {
    printf("destroy lock\n");
    mutex->unlock();
}
