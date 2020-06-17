#include "../include/dt/dtusuario.h"
#include <string>

DtUsuario::DtUsuario(std::string nombre, std::string email, std::string imagen, std::string contrasenia){
    this->nombre = nombre;
    this->email = email;
    this->imagen = imagen;
    this->contrasenia = contrasenia;
}

DtUsuario::~DtUsuario() {}

std::string DtUsuario::getNombre(){
    return this->nombre;
}

std::string DtUsuario::getEmail(){
    return this->email;
}

std::string DtUsuario::getImagen(){
    return this->imagen;
}

std::string DtUsuario::getContrasenia(){
    return this->contrasenia;
}