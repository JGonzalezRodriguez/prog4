#include "handlerasignaturas.h"

HandlerAsignaturas* HandlerAsignaturas::getInstancia() {

}
std::map<string, Asignatura*> HandlerAsignaturas::get() {
    std::map<string, Asignatura*> x;
    return x;
}
Asignatura* HandlerAsignaturas::find(string codigo) {
    return NULL;
}

void HandlerAsignaturas::remove(Asignatura* a) {

}
