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