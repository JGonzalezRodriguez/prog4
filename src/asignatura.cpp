#include "../include/asignatura.h"
#include "../include/estudiante.h"

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