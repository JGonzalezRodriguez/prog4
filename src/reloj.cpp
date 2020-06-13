#include "../include/reloj.h"
#include "../include/dt/dtfecha.h"

Reloj::Reloj(DtFecha* fecha) {
    this->fecha = fecha;
}

DtFecha* Reloj::getFecha() {
    return this->fecha;
}

void Reloj::setFecha(DtFecha* fecha) {
    delete this->fecha;
    this->fecha = fecha;
}