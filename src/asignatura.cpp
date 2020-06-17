#include "../include/asignatura.h"

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
    return NULL;
}

void Asignatura::addClase(Clase* c) {

}

std::set<Clase*> Asignatura::getClases() {
    std::set<Clase*> x;
    return x;
}

std::string getNombre() {
    return NULL;
}
std::string getCodigo() {
    return NULL;
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

DtAsignatura* Asignatura::getDt() {
    DtAsignatura* x = new DtAsignatura(this->nombre, this->codigo);
    return x;
}