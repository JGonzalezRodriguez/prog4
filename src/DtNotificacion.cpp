#include "../include/DtNotificacion.h"

DtNotificacion::DtNotificacion(DtFecha* fechayhoraenviado, std::string nombreclase, std::string idclase, DtAsignatura* asignatura){
    this->fechayhoraenviado = fechayhoraenviado;
    this->nombreclase = nombreclase;
    this->idclase = idclase;
    this->asignatura = asignatura;
}

DtNotificacion::~DtNotificacion(){}

DtFecha* DtNotificacion::getFechaYHoraEnviado(){
    return this->fechayhoraenviado;
}

std::string DtNotificacion::getNombreClase(){
    return this->nombreclase;
}

std::string DtNotificacion::getIdClase(){
    return this->idclase;
}

DtAsignatura* DtNotificacion::getAsignatura(){
    return this->asignatura;
}
