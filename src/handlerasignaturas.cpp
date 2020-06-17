#include "../include/handlerasignaturas.h"

HandlerAsignaturas* HandlerAsignaturas::getInstancia() {
    return NULL;
}
std::map<std::string, Asignatura*> HandlerAsignaturas::get() {
    std::map<std::string, Asignatura*> x;
    return x;
}
Asignatura* HandlerAsignaturas::find(std::string codigo) {
    return NULL;
}

void HandlerAsignaturas::remove(Asignatura* a) {

}

void HandlerAsignaturas::add(Asignatura* a) {
    //confirmando unicidad del codigo
    std::string codigo = a->getCodigo();
    if (this->find(codigo) != NULL){
        throw std::invalid_argument("\nYa existe una asignatura con ese codigo");
    }
    //agregando
    this->mapasignaturas.insert(std::pair<std::string, Asignatura*>(codigo, a));

}