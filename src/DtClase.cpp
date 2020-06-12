#include "../include/dt/dtclase.h"
#include <string>

DtClase::DtClase(DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente){
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->fechayhorafinal = fechayhorafinal;
    this->envivo = envivo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
}

std::string DtClase::getId(){
    return this->id;
}

std::string DtClase::getUrl(){
    return this->url;
}

std::string DtClase::getNombre(){
    return this->nombre;
}

DtFecha* DtClase::getFechaYHoraComienzo(){
    return this->fechayhoracomienzo;
}

DtFecha* DtClase::getFechaYHoraFinal(){
    return this->fechayhorafinal;
}

DtDocente* DtClase::getDocente(){
    return this->docente;
}