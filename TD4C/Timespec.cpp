#include "Timespec.h"

Timespec::Timespec() { }

Timespec operator+(Timespec ts1, Timespec ts2) {
    /**
     * Surcharge de l'opérateur '+' afin de prendre en compte le passage de n_sec à sec
     */
    ts1.tv_sec += ts2.tv_sec + (ts1.tv_nsec + ts2.tv_nsec) / 1000000000; // Renormalisation des secondes
    ts1.tv_nsec += ts2.tv_nsec;
    ts1.tv_nsec %= 1000000000; // Renormalisation des nanosecondes
    return ts1;
}

Timespec Timespec::from_ms(double t_ms) {
    /**
     * Pour un double t_ms (temps en ms) donné, renvoie le Timespec convertit
     */
    this->tv_nsec = fmod(t_ms, 1000) * 1000000;
    this->tv_sec = (__time_t) (t_ms / 1000);
}

double Timespec::to_ms() {
    /**
     * Pour un Timespec donné, renvoie un double correspondant au nombre de ms dans ce Timespec
     */
    double result = 0;
    result += this->tv_nsec / 1000000 + this->tv_sec * 1000;

    return result;
}
