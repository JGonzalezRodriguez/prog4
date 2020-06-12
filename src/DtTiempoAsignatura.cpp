#include "../include/DtTiempoAsignatura.h"

DtTiempoAsignatura::DtTiempoAsignatura(std::string asignatura, DtFecha* tiempo){
    this->asignatura = asignatura;
    this->tiempo = tiempo;
}

DtTiempoAsignatura::~DtTiempoAsignatura(){}

DtTiempoAsignatura::getAsignatura(){
    return this->asignatura;
}

DtTiempoAsignatura::getTiempo(){
    return this->tiempo;
}
