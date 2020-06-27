#include <stdexcept>
#include "../include/docente.h"

instituto Docente::getInstituto(){
    return this->inst;
}
void Docente::setInstituto(instituto inst){
    this->inst = inst;
}

//operaciones de usuario que sobreescribe
std::set<Clase*> Docente::listarClases(){
    return this->clases;
}
bool Docente::tieneAsignatura(Asignatura *a){
    return false;
}
Clase* Docente::elegirClase(std::string id){
    for (std::set<Clase*>::iterator it=this->clases.begin(); it!=this->clases.end(); ++it){
        Clase* c = *it; 
        if (c->getId() == id){
            return c;
        }
    }
    //si el docente no esta en ninguna clase con ese id
    throw std::invalid_argument("\nEl usuario no tiene está en ninguna clase con ese ID");
}
       
//operaciones mismas de docente
void Docente::addAsignatura(Dicta *dicta){
    this->dictas.insert(dicta);
}

void Docente::deslinkearClase(Clase* c){
    this->clases.erase(c);
}

void Docente::deslinkear(Dicta *dicta){
    this->dictas.erase(dicta);
}
std::set<Asignatura*> Docente::getAsignaturas(){
    std::set<Asignatura*> x;
    for (std::set<Dicta*>::iterator it=this->dictas.begin(); it!=this->dictas.end(); ++it) {
        Dicta* dic = *it; 
        x.insert(dic->getAsignatura());
    }
    return x;
}
modalidad Docente::getModalidad(Asignatura *a){
    modalidad mod;
    for (std::set<Dicta*>::iterator it=this->dictas.begin(); it!=this->dictas.end(); ++it) {
        Dicta* dic = *it; 
        if (dic->getAsignatura() == a) {
            mod = dic->getModalidad();
        }
    }
    return mod;
}
void Docente::addClase(Clase *c){
    clases.insert(c);
}
std::set<Clase*> Docente::getClasesEnVivo(){
    std::set<Clase*> x;
    for (std::set<Clase*>::iterator it=this->clases.begin(); it!=this->clases.end(); ++it) {
        Clase* c = *it;
        if (c->getEnVivo())
            x.insert(c);
    }
    return x;
}
std::set<Clase*> Docente::getClasesFinalizadas() {
    std::set<Clase*> x;
    for (std::set<Clase*>::iterator it=this->clases.begin(); it!=this->clases.end(); ++it) {
        Clase* c = *it;
        if (!(c->getEnVivo()))
            x.insert(c);
    }
    return x;
}

Clase *Docente::getClase(std::string id){
    Clase* c = NULL;
    for (std::set<Clase*>::iterator it=this->clases.begin(); it!=this->clases.end(); ++it) {
        //printf("ITERANDO-");
        //std::cout << (*it)->getId() << "-VS-";
        //std::cout << id;
        //printf("-DEBUG-");
        if ((*it)->getId() == id) {
            c = *it;
        }
    }
    if (c == NULL) {
        throw std::invalid_argument("No hay una clase valida con ese ID");
    } else {
        return c;
    }
}
Asignatura *Docente::getAsignatura(std::string codigo){
    return NULL;
}

Docente::Docente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto instituto):Usuario(nombre, email, imagen, contrasenia){
    this->inst = instituto;
}

DtDocente* Docente::getDt(){
    DtDocente* x = new DtDocente(this->getInstituto(), this->getNombre(), this->getEmail(), this->getImagen(), this->getContrasenia());
    return x;
}
