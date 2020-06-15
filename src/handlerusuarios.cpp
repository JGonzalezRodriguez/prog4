#include <stdexcept>
#include "../include/handlerusuarios.h"
//deberiamos cambiar Handlerusuarios a HandlerUsuarios, o ya fue?

Handlerusuarios* Handlerusuarios::instancia = NULL;

Handlerusuarios::Handlerusuarios(){

}

Handlerusuarios* Handlerusuarios::getInstancia(){
    if(instancia == NULL)
        instancia = new Handlerusuarios();
    return instancia;
}

void Handlerusuarios::add(Usuario* u){
    //confirmando unicidad del email
    if (this->getUsuario(u->getEmail()) != NULL){
        throw std::invalid_argument("\nYa existe un usuario con ese email");
    }
    //agregando
    Estudiante* est = dynamic_cast<Estudiante*>(u);
    if (est != NULL){ // es estudiante
        this->estudiantes.insert(est);
    }
    Docente* doc = dynamic_cast<Docente*>(u);
    if (doc != NULL){ // es docente 
        this->docentes.insert(doc);
    }
}

std::set<Docente*> Handlerusuarios::getDocentes(){
    return this->docentes;
}

Docente* Handlerusuarios::getDocente(std::string email){
    for (std::set<Docente*>::iterator it=this->docentes.begin(); it!=this->docentes.end(); ++it){
        Docente* doc = *it;
        if (doc->getEmail() == email){
            return doc;
        } 
    }
    return NULL;
}

bool Handlerusuarios::identificarse(std::string email, std::string contrasenia){
    Usuario* u = this->getUsuario(email);
    if (u == NULL || u->getContrasenia() != contrasenia){
        return false;
    }
    return true;
}

Estudiante* Handlerusuarios::getEstudiante(std::string email){
    for (std::set<Estudiante*>::iterator it=this->estudiantes.begin(); it!=this->estudiantes.end(); ++it){
        Estudiante* est = *it;
        if (est->getEmail() == email){
            return est;
        } 
    }
    return NULL;
}

Usuario* Handlerusuarios::getUsuario(std::string email){
    Estudiante* est = this->getEstudiante(email);
    if (est != NULL){
        return est;
    }
    Docente* doc = this->getDocente(email);
    if (doc != NULL){
        return doc;
    }
    return NULL;
}

void Handlerusuarios::notificar(Asignatura* a, Mensaje* m){
}

void Handlerusuarios::addSubscripto(Usuario* u){
}

void Handlerusuarios::removerSubscripto(Usuario* u){
}