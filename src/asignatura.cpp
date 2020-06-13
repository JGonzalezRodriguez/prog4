#include "../include/asignatura.h"

Asignatura::Asignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) {

}

void Asignatura::addDocente(Dicta* dic) {

}

void Asignatura::addEstudiante(Estudiante* e) {
    
}

std::set<Estudiante*> Asignatura::getEstudiantes() {
    std::set<Estudiante*> x;
    return x;
}

Estudiante* Asignatura::getEstudiante(std::string CI) {
    return NULL;
}

void Asignatura::addClase(Clase* c) {

}

std::set<Clase*> Asignatura::getClases() {
    return NULL;
}

std::string getNombre() {
    return NULL;
}
std::string getCodigo() {
    return NULL;
}

bool tieneTeo() {
    return true
}   

bool tienePrac() {
    return true
}

bool tieneMon() {
    return true
}