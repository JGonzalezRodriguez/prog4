#include "../include/asignatura.h"
#include "../include/estudiante.h"

Asignatura::Asignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->tieneteo = tieneteo;
    this->tieneprac = tieneprac;
    this->tienemon = tienemon;
}

void Asignatura::addDocente(Dicta* dic) {
    this->dictas.insert(dic);
}

void Asignatura::addEstudiante(Estudiante* e) {
    this->estudiantes.insert(e);
}

std::set<Estudiante*> Asignatura::getEstudiantes() {
    return this->estudiantes;
}

Estudiante* Asignatura::getEstudiante(std::string CI) {
    for (std::set<Estudiante*>::iterator it=this->estudiantes.begin(); it!=this->estudiantes.end(); ++it){
        Estudiante* est = *it;
        if (est->getCi() == CI){
            return est;
        } 
    }
    return NULL;
}

void Asignatura::addClase(Clase* c) {
    clases.insert(c);
}

std::set<Clase*> Asignatura::getClases() {
    return this->clases;
}

std::string Asignatura::getNombre() {
    return this->nombre;
}
std::string Asignatura::getCodigo() {
    return this->codigo;
}

bool Asignatura::tieneTeo() {
    return this->tieneteo;
}   

bool Asignatura::tienePrac() {
    return this->tieneprac;
}

bool Asignatura::tieneMon() {
    return this->tienemon;
}

std::set<Dicta*> Asignatura::getDictas() {
    return this->dictas;
}

DtAsignatura* Asignatura::getDt() {
    DtAsignatura* x = new DtAsignatura(this->nombre, this->codigo);
    return x;
}