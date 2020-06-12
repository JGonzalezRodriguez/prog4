#include "../include/DtClase.h"

DtClase::DtClase(DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente){
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->fechayhorafinal = fechayhorafinal;
    this->envivo = envivo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
}

void DtClase::getId(){
    return this->id;
}

void DtClase::getUrl(){
    return this->url;
}

void DtClase::getNombre(){
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

void DtClase::setId(std::string id){
    this->id = id;
}

void DtClase::setUrl(std::string url){
    this->url = url;
}

void DtClase::setNombre(std::string nombre){
    this->nombre = nombre;
}

void DtClase::setFechaYHoraComienzo(DtFecha* fecha){
    this->fechayhoracomienzo = fecha;
}

void DtClase::setFechaYHoraFinal(DtFecha* fecha){
    this->fechayhorafinal = fecha;
}

void DtClase::setDocente(DtDocente* docente){
    this->docente = docente;
}