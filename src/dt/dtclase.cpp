#include "../include/dt/dtclase.h"
#include <string>
#include <ostream>

DtClase::DtClase(modalidad mod, DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente){
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->fechayhorafinal = fechayhorafinal;
    this->envivo = envivo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
    this->mod = mod;
}

DtClase::DtClase(modalidad mod, std::set<DtEstudiante*> estudiantes,DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente) {
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->fechayhorafinal = fechayhorafinal;
    this->envivo = envivo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
    this->mod = mod;
    this->estudiantes = estudiantes;
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

modalidad DtClase::getMod() {
    return this->mod;
}

std::ostream& operator<< (std::ostream& os, DtClase &b) {
    if (b.getFechaYHoraFinal() != NULL){
        os << "Fecha comiezo: " << *(b.getFechaYHoraComienzo()) << std::endl << "Fecha final: " << *(b.getFechaYHoraFinal()) << std::endl << "Id: " << b.getId() << std::endl << "Url: " << b.getUrl() << std::endl << "Docente: " << *(b.getDocente()) << std::endl << "Nombre: " << b.getNombre() << std::endl;
    }else{
        os << "Fecha comiezo: " << *(b.getFechaYHoraComienzo()) << std::endl << "Fecha final: - "  << std::endl << "Id: " << b.getId() << std::endl << "Url: " << b.getUrl() << std::endl << "Docente: " << *(b.getDocente()) << std::endl << "Nombre: " << b.getNombre() << std::endl;
    }
    return os;
}