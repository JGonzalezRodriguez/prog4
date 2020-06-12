#include "../include/DtPromAsistencia.h"

DtPromAsistencia::DtPromAsistencia(std::string clase, int tiempoprom){
    this->clase = clase; //codigo? TODO:cambiar nombre para que sea mas descriptivo?
    this->tiempoprom = tiempoprom;
}

DtPromAsistencia::~DtPractico(){}

std::string DtPromAsistencia::getClase(){
    return this->clase;
}

int DtPromAsistencia::getTiempoProm(){
    return this->tiempoprom;
}
