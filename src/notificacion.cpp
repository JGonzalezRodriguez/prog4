#include "../include/Notificacion.h"

Notificacion::Notificacion(Mensaje* mensaje){
    this->mensaje = mensaje;
}

Notificacion::~Notificacion(){}

Mensaje* Notificacion::getMensaje(){
    return this->mensaje;
}

bool Notificacion::esDeAsignatura(){
    //TODO
    return false;
}