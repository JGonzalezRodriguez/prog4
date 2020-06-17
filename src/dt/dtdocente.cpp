#include "../include/dt/dtdocente.h"
#include <string>
#include <ostream>

DtDocente::DtDocente(instituto inst, std::string nombre, std::string email, std::string imagen, std::string contrasenia):DtUsuario(nombre, email, imagen, contrasenia){
    //primero ejecuta el constructor de DtUsuario
    this->inst = inst;
}

DtDocente::~DtDocente(){}

instituto DtDocente::getInstituto(){
    return this->inst;
}

std::ostream& operator<< (std::ostream& os, DtDocente &b) {
    os << "Nombre: " << b.getNombre() << std::endl << "Email: " << b.getEmail() << std::endl << "Imagen: " << b.getImagen() << std::endl << "Instituto: " << b.getInstituto() << std::endl;
    return os;
}
//es necesario mostrar la contraseña?