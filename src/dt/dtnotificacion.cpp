#include "../include/dt/dtnotificacion.h"

DtNotificacion::DtNotificacion(DtFecha* fechayhoraenviado, std::string nombreautor, std::string textomsj, std::string nombreclase, std::string idclase, DtAsignatura* asignatura){
    this->nombreautor = nombreautor;
    this->textomsj = textomsj;
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

std::string DtNotificacion::getNombreAutor(){
    return this->nombreautor;
}

std::string DtNotificacion::getTextoMsj(){
    return this->textomsj;
}

std::ostream& operator<< (std::ostream& os, DtNotificacion &b) {
    os << "Fecha enviado: " << *(b.getFechaYHoraEnviado()) << std::endl << "Nombre autor: " << b.getNombreAutor() << std::endl << "Texto del mensaje: " << b.getTextoMsj() << std::endl << "Nombre clase: " << b.getNombreClase() << std::endl << "ID clase: " << b.getIdClase() << std::endl << "Asignatura: " << *(b.getAsignatura()) << std::endl;
    return os;
}
