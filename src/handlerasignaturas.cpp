#include <stdexcept>
#include "../include/handlerasignaturas.h"

HandlerAsignaturas* HandlerAsignaturas::instancia = NULL;

HandlerAsignaturas* HandlerAsignaturas::getInstancia() {
    if(instancia == NULL)
        instancia = new HandlerAsignaturas();
    return instancia;
}

HandlerAsignaturas::HandlerAsignaturas(){

}

std::map<std::string, Asignatura*> HandlerAsignaturas::get() {
    return this->mapasignaturas;
}

Asignatura* HandlerAsignaturas::find(std::string codigo) {
    std::map<std::string, Asignatura*>::iterator it = this->mapasignaturas.find(codigo);
    if (it != this->mapasignaturas.end()){ // si encontro (cuando no encuentra devuelve end())
        return it->second;
    }
    return NULL;
}

void HandlerAsignaturas::remove(Asignatura* a) {
    this->mapasignaturas.erase(a->getCodigo());
}

void HandlerAsignaturas::add(std::string codigo, Asignatura* a) {
    //confirmando unicidad del codigo
    if (this->find(codigo) != NULL){
        throw std::invalid_argument("\nYa existe una asignatura con ese codigo");
    }
    //agregando
    this->mapasignaturas.insert(std::pair<std::string, Asignatura*>(a->getCodigo(), a));
}