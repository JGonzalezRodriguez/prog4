#include "../include/dt/dttiempoasignatura.h"
#include <string>

DtTiempoAsignatura::DtTiempoAsignatura(std::string asignatura, int horas, int mins){
    this->asignatura = asignatura;
    this->horas = horas;
    this->mins = mins;
}

DtTiempoAsignatura::~DtTiempoAsignatura(){}

std::string DtTiempoAsignatura::getAsignatura(){
    return this->asignatura;
}

int DtTiempoAsignatura::getHoras(){
    return this->horas;
}
int DtTiempoAsignatura::getMins(){
    return this->mins;
}

std::ostream& operator<< (std::ostream& os, DtTiempoAsignatura &b){
    os << "*Asignatura: " << b.getAsignatura() << std::endl << "Horas: " << b.getHoras() << std::endl << "Minutos: " << b.getMins() << std::endl;
    return os;

}