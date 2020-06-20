#include "../include/dt/dtpromasistencia.h"
#include "../include/dt/dtclase.h"

DtPromAsistencia::DtPromAsistencia(DtClase* clase, int horas, int mins) {
    this->clase = clase; //codigo? TODO:cambiar nombre para que sea mas descriptivo?
    this->horas = horas;
    this->mins = mins;
}

DtPromAsistencia::~DtPromAsistencia(){}

DtClase* DtPromAsistencia::getClase(){
    return this->clase;
}

int DtPromAsistencia::getHoras(){
    return this->horas;
}
int DtPromAsistencia::getMins(){
    return this->mins;
}

std::ostream& operator<< (std::ostream& os, DtPromAsistencia &b){
    os << *(b.getClase()) << std::endl << "Tiempo promedio de asistencia: "  << std::endl << b.getHoras() << ":" << b.getMins() << std::endl << std::endl;
    return os;

}