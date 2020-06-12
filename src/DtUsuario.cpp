#include "../include/DtUsuario.h"

DtUsuario::DtUsuario(std::string nombre, std::string email, std::string imagen, std::string contrasenia){
    this->nombre = nombre;
    this->email = email;
    this->imagen = imagen;
    this->contrasenia = contrasenia;
}

void DtUsuario::getNombre(){
    return this->nombre;
}

void DtUsuario::getEmail(){
    return this->email;
}

void DtUsuario::getImagen(){
    return this->imagen;
}

void DtUsuario::getContrasenia(){
    return this->contrasenia;
}