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

void add(std::string codigo, Asignatura* a) {

}