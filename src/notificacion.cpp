#include "../include/notificacion.h"

Notificacion::Notificacion(Mensaje* mensaje){
    this->mensaje = mensaje;
}

Notificacion::~Notificacion(){}

Mensaje* Notificacion::getMensaje(){
    return this->mensaje;
}

bool Notificacion::esDeAsignatura(Asignatura* a){
    if (mensaje->getAsignatura() == a) {
        return true;
    }
    return false;
}