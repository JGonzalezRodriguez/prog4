#include "../include/dt/dtestudiante.h"

DtEstudiante::DtEstudiante(std::string ci, std::string nombre, std::string email, std::string imagen, std::string contrasenia):DtUsuario(nombre, email, imagen, contrasenia){
    //primero ejecuta el constructor de DtUsuario
    this->ci = ci;
}

DtEstudiante::~DtEstudiante(){}

std::string DtEstudiante::getCi(){
    return this->ci;
}

std::ostream& operator<< (std::ostream& os, DtEstudiante &b) {
    os << "Nombre: " << b.getNombre() << std::endl << "Email: " << b.getEmail() << std::endl << "Imagen: " << b.getImagen() << std::endl << "Contrasenia: " << b.getContrasenia() << std::endl << "CI: " << b.getCi() << std::endl;
    return os;
}