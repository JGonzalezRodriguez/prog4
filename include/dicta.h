#ifndef DICTA_H
#define DICTA_H

#include "dt/enums.h"
#include "docente.h"
#include "asignatura.h"

class Dicta {
    private:
        modalidad modalidad;
        Docente* doc;
        Asignatura* asig;
    public:
        Dicta(modalidad modalidad,Docente* doc, Asignatura* asig);
        Docente* getDocente();
        void deslinkearDocente();
        Asignatura* getAsignatura();
        modalidad getModalidad();
};

#endif