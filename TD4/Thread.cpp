/** @file */

#include "Thread.h"
#include <stdio.h>
#include "Lock.h"

Thread::Thread(int schedPolicy) : schedPolicy(schedPolicy) {
    /**
     * Runtime d'une thread.
     */
    pthread_attr_init(&attr);
    condition = Condition(true);
    started = false;
}

bool Thread::start(int priority) {
    /**
     * Runtime de démarrage d'une thread.
     */
    bool result;

    {
        Lock lock(&condition);
        while (started) {
            condition.wait();
            result = false;
        }
        started = true;
    }

    pthread_attr_setschedpolicy(&attr, schedPolicy);
    sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &schedParams);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_create(&tid, &attr, call_run, this);
    return result;
}

void Thread::join() {
    /**
     * Tentative de destruction de la thread.
     */
    pthread_join(tid, NULL);
}

int Thread::join(double timeout_ms) {
    /**
     * Version avec timeout.
     */
    pthread_join(tid, NULL);
    Timespec t;
    t.from_ms(timeout_ms);

    return pthread_timedjoin_np(tid, NULL, &t);
}

void *Thread::call_run(void *arg_pointer) {
    /**
     * Appelle la fonction run.
     * Nécessaire pour être passé en argument de pthread_create.
     */
    Thread *t = (Thread *) arg_pointer;
    t->run();
    Lock lock(&(t->condition));
    t->started = false;
    (t->condition).notify();
}

void Thread::run() {
    /**
     * Fonction executrice.
     */
    printf("RUN sans rien\n");
}

void Thread::sleep(double delay_ms) {
    /**
     * Ajoute un délai.
     */
    Timespec t;
    t.from_ms(delay_ms);

    nanosleep(&t, NULL);
}

void Thread::setStackSize(size_t stackSize) {
    /**
     * Fixe la taille de la pile.
     */
    printf("SET STACK SIZE LAUNCHED\n");
    pthread_attr_setstacksize(&attr, stackSize);
}

