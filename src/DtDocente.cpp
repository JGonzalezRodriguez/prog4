#include "../include/DtDocente.h"

DtDocente::DtDocente(instituto instituto, std::string nombre, std::string email, std::string imagen, std::string contrasenia):DtUsuario(nombre, email, imagen, string){
    //primero ejecuta el constructor de DtUsuario
    this->instituto = instituto;
}

DtDocente::~DtDocente(){}

instituto DtDocente::getInstituto(){
    return this->instituto;
}
