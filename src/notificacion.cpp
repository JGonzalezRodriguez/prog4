#include "../include/notificacion.h"

Notificacion::Notificacion(Mensaje* mensaje){
    this->mensaje = mensaje;
}

Notificacion::~Notificacion(){}

Mensaje* Notificacion::getMensaje(){
    return this->mensaje;
}

bool Notificacion::esDeAsignatura(Asignatura* a){
    //TODO
    return false;
}