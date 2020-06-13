#include "../include/reloj.h"
#include "../include/dt/dtfecha.h"

Reloj * Reloj::instancia = nullptr;


Reloj::Reloj(DtFecha* fecha) {
    this->fecha = fecha;
}

Reloj * Reloj::getInstancia() {
    if (instancia == nullptr) {
        DtFecha f = DtFecha(1,1,1,1,1,1);
        instancia = Reloj(f);
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