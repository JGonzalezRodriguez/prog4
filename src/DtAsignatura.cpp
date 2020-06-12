#include "../include/DtAsignatura.h"

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

void DtAsignatura::setNombre(std::string nombre){
    this->nombre = nombre;
}

void DtAsignatura::setCodigo(std::string codigo){
    this->codigo = codigo;
}