#include "docente.h"

instituto Docente::getInstituto(){
    return this->instituto;
}
void Docente::setInstituto(instituto instituto){
    this->instituto = instituto;
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
Clase *Docente::getClase(string id){
    return NULL;
}
Asignatura *Docente::getAsignatura(string codigo){
    return NULL;
}

Docente::Docente(string nombre, string email, string contrasenia, string imagen, instituto instituto):Usuario(nombre, email, imagen, contrasenia){
    this->instituto = instituto;
}

