#include "../include/dicta.h"


Dicta::Dicta(modalidad modalidad, Docente* doc, Asignatura* asig){
    this->mod = modalidad;
    this->doc = doc;
    this->asig = asig;
};

Docente* Dicta::getDocente(){
    return this->doc;
};

void Dicta::deslinkearDocente() {
    //doc->deslinkear(this);
};

Asignatura* Dicta::getAsignatura() {
    return this->asig;
};

modalidad Dicta::getModalidad() {
    return this->mod;
};