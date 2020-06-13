#include "../include/docente.h"

instituto Docente::getInstituto(){
    return this->inst;
}
void Docente::setInstituto(instituto inst){
    this->inst = inst;
}

//operaciones que hereda de usuario
std::set<Clase*> Docente::listarClases(){
    return NULL;
}
bool Docente::tieneAsignatura(Asignatura *a){
    return false;
}
       
//operaciones mismas de docente
void Docente::addAsignatura(Dicta *dicta){

}
void Docente::deslinkear(Dicta *dicta){

}
Asignatura *Docente::getAsignaturas(){
    return NULL;
}
modalidad *Docente::getModalidad(Asignatura *a){
    return NULL;
}
void Docente::addClase(Clase *c){

}
std::set<Clase*> Docente::getClasesEnVivo(){
    return NULL;
}
Clase *Docente::getClase(std::string id){
    return NULL;
}
Asignatura *Docente::getAsignatura(std::string codigo){
    return NULL;
}

Docente::Docente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto instituto):Usuario(nombre, email, imagen, contrasenia){
    this->instituto = instituto;
}

