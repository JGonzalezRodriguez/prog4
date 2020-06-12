#include "../include/dt/dttiempoasignatura.h"
#include <string>

DtTiempoAsignatura::DtTiempoAsignatura(std::string asignatura, DtFecha* tiempo){
    this->asignatura = asignatura;
    this->tiempo = tiempo;
}

DtTiempoAsignatura::~DtTiempoAsignatura(){}

std::string DtTiempoAsignatura::getAsignatura(){
    return this->asignatura;
}

DtFecha* DtTiempoAsignatura::getTiempo(){
    return this->tiempo;
}
