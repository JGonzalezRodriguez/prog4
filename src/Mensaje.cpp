#include "../include/Mensaje.h"

Mensaje::Mensaje(std::string texto, Clase* clase){
    //TODO: generar ID
    this->clase = clase;
    this->texto = texto;
    this->respondidopor = set<Mensaje*>(); //new empty set
    //TODO: get fecha actual del sistema
}

Mensaje::~Mensaje(){}

Asignatura* Mensaje::getAsignatura(){
    return this->clase->asignatura;
}

Clase* Mensaje::getClase(){
    return this->clase;
}

DtFecha Mensaje::getFechaYHoraEnviado(){
    return this->fechayhoraenviado;
}

std::string Mensaje::getTexto(){
    return this->texto;
}

std::string Mensaje::getId(){
    return this->id;
}

std::set<Mensaje*> Mensaje::getHijos(){
    return this->respondidopor;
}

void Mensaje::agregarHijo(Mensaje* m){
    //TODO
}
