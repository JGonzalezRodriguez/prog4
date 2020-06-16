#include "../include/asignatura.h"

Asignatura::Asignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->tieneteo = tieneteo;
    this->tieneprac = tieneprac;
    this->tienemon = tienemon;
}

void Asignatura::addDocente(Dicta* dic) {

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

std::string Asignatura::getNombre() {
    return this->nombre;
}
std::string Asignatura::getCodigo() {
    return this->codigo;
}

bool Asignatura::tieneTeo() {
    return true;
}   

bool Asignatura::tienePrac() {
    return true;
}

bool Asignatura::tieneMon() {
    return true;
}