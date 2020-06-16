#include "../include/docente.h"

instituto Docente::getInstituto(){
    return this->inst;
}
void Docente::setInstituto(instituto inst){
    this->inst = inst;
}

//operaciones que hereda de usuario
std::set<Clase*> Docente::listarClases(){
    std::set<Clase*> x;
        return x;
}
bool Docente::tieneAsignatura(Asignatura *a){
    return false;
}
       
//operaciones mismas de docente
void Docente::addAsignatura(Dicta *dicta){

}
void Docente::deslinkear(Dicta *dicta){

}
std::set<Asignatura*> Docente::getAsignaturas(){
    std::set<Asignatura*> x;
    return x;

}
modalidad Docente::getModalidad(Asignatura *a){
    return modalidad(1);
}
void Docente::addClase(Clase *c){

}
std::set<Clase*> Docente::getClasesEnVivo(){
    std::set<Clase*> x;
    return x;
}
Clase *Docente::getClase(std::string id){
    return NULL;
}
Asignatura *Docente::getAsignatura(std::string codigo){
    return NULL;
}

Docente::Docente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto instituto):Usuario(nombre, email, imagen, contrasenia){
    this->inst = instituto;
}

