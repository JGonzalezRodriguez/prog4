#include "../include/dt/dtpreview.h"
#include <string>
#include <ostream>

DtPreview::DtPreview(modalidad mod, DtFecha* fechayhoracomienzo, std::string id, std::string nombre, std::string url, DtDocente* docente){
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
    this->mod = mod;
}

DtPreview::DtPreview(modalidad mod, std::set<DtEstudiante*> estudiantes,DtFecha* fechayhoracomienzo, std::string id, std::string nombre, std::string url, DtDocente* docente) {
    this->fechayhoracomienzo = fechayhoracomienzo;
    this->id = id;
    this->nombre = nombre;
    this->url = url;
    this->docente = docente;
    this->mod = mod;
    this->estudiantes = estudiantes;
}

std::string DtPreview::getId(){
    return this->id;
}

std::string DtPreview::getUrl(){
    return this->url;
}

std::string DtPreview::getNombre(){
    return this->nombre;
}

DtFecha* DtPreview::getFechaYHoraComienzo(){
    return this->fechayhoracomienzo;
}

DtDocente* DtPreview::getDocente(){
    return this->docente;
}

modalidad DtPreview::getMod() {
    return this->mod;
}

std::set<DtEstudiante*> DtPreview::getEstudiantes() {
    return this->estudiantes;
}


std::ostream& operator<< (std::ostream& os, DtPreview &b) {
    os << "Fecha comiezo: " << *(b.getFechaYHoraComienzo()) << std::endl << "Id: " << b.getId() << std::endl << "Url: " << b.getUrl() << std::endl << "Modalidad: " << b.getMod() << std::endl << "Docente: " << std::endl << *(b.getDocente()) << std::endl << "Nombre: " << b.getNombre() << std::endl;
    return os;
}