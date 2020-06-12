#ifndef DICTA_H
#define DICTA_H

#include "modalidad.h"
#include "Doente.h"
#include "Asignatura.h"

class Dicta {
    private:
        Dicta();
        modalidad modalidad;
        Docente* doc;
        Asignatura* asig;
    public:
        Dicta(modalidad modalidad,Docente* doc, Asignatura* asig);
        Docente getDocente();
        void deslinkearDocente();
        Asignatura getAsignatura();
        modalidad getModalidad();
};

#endif