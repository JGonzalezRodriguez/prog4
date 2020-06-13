#include "../include/reloj.h"
#include "../include/dt/dtfecha.h"

Reloj * Reloj::instancia = NULL;


Reloj::Reloj(DtFecha* fecha) {
    this->fecha = fecha;
}

Reloj * Reloj::getInstancia() {
    if (instancia == NULL) {
        DtFecha* f = new DtFecha(1,1,1,1,1);
        instancia = new Reloj(f);
    }
    return instancia;
}

DtFecha* Reloj::getFecha() {
    return this->fecha;
}

void Reloj::setFecha(DtFecha* fecha) {
    delete this->fecha;
    this->fecha = fecha;
}