#include "../include/DtEstudiante.h"

DtDocente::DtDocente(std::string ci, std::string nombre, std::string email, std::string imagen, std::string contrasenia):DtUsuario(nombre, email, imagen, string){
    //primero ejecuta el constructor de DtUsuario
    this->ci = ci;
}

DtEstudiante::~DtEstudiante(){}

std::string DtEstudiante::getCi(){
    return this->ci;
}