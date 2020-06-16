#include "../include/dt/dtasignatura.h"

DtAsignatura::DtAsignatura(std::string nombre, std::string codigo){
    this->nombre = nombre;
    this->codigo = codigo;
}

DtAsignatura::~DtAsignatura(){}

std::string DtAsignatura::getNombre(){
    return this->nombre;
}

std::string DtAsignatura::getCodigo(){
    return this->codigo;
}

std::ostream& operator<< (std::ostream& os, DtAsignatura &b) {
    os << "Nombre: " << b.getNombre() << std::endl << "Código: " << b.getCodigo() << std::endl;
    return os;
}