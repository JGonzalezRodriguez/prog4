#include "../include/Dicta.h"


Dicta::Dicta(modalidad modalidad, Docente* doc, Asignatura* asig){
    Dicta dicta_nuevo = new Dicta;
    dicta_nuevo.modalidad = modalidad;
    dicta_nuevo.doc = doc;
    dicta_nuevo.asig = asig;
    return dicta_nuevo;
};

Dicta::Docente Dicta::getDocente(){
    return this->doc;
};

void Dicta::deslinkearDocente() {
};

Asignatura Dicta::getAsignatura() {
    return this->asig;
};

modalidad Dicta::getModalidad() {
    return this->modalidad;
};

Dicta::~Dicta() {
    this->doc = NULL;
    this->asig = NULL;
}