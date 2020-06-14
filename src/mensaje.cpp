#include "../include/mensaje.h"

int Mensaje::seed = 1; //compile time B)

Mensaje::Mensaje(std::string texto, Clase* clase){
    this->id = std::to_string(this->seed);  // si no compila 
    this->seed++;                           // cambiar a Mensaje::seed
    this->clase = clase;
    this->texto = texto;
    Reloj* r = Reloj::getInstancia();
    DtFecha* f = new DtFecha(r->getFecha()); // f es una copia de dtfecha que hay en ese instante en el reloj
    this->fechayhoraenviado = f;         
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
