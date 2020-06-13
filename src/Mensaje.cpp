#include "../include/Mensaje.h"

int Mensaje::seed = 1; //compile time B)

Mensaje::Mensaje(std::string texto, Clase* clase){
    this->id = std::to_string(this->seed);  // si no compila 
    this->seed++;                           // cambiar a Mensaje::seed
    this->clase = clase;
    this->texto = texto;
    this->fechayhoraenviado = Reloj::getFecha()          // hay que hacer el reloj!
}

Mensaje::~Mensaje(){}

Asignatura* Mensaje::getAsignatura(){
    return this->clase->getAsignatura();
}

Clase* Mensaje::getClase(){
    return this->clase;
}

DtFecha* Mensaje::getFechaYHoraEnviado(){
    return this->fechayhoraenviado;
}

std::string Mensaje::getTexto(){
    return this->texto;
}

std::string Mensaje::getId(){
    return this->id;
}

// std::set<Mensaje*> Mensaje::getHijos(){
//     return this->respondidopor;
// }

void Mensaje::agregarHijo(Mensaje* m){
    //TODO
}
