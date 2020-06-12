#include "../include/dt/dtdocente.h"
#include <string>

DtDocente::DtDocente(instituto inst, std::string nombre, std::string email, std::string imagen, std::string contrasenia):DtUsuario(nombre, email, imagen, string){
    //primero ejecuta el constructor de DtUsuario
    this->inst = inst;
}

DtDocente::~DtDocente(){}

instituto DtDocente::getInstituto(){
    return this->inst;
}
