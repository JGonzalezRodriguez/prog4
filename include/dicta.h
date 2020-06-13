#ifndef DICTA_H
#define DICTA_H

#include "dt/enums.h"
#include "docente.h"
#include "asignatura.h"

class Dicta {
    private:
        modalidad mod;
        Docente* doc;
        Asignatura* asig;
    public:
        /**
        Crea Dicta y asocia doc y asig, tambien crea la asociacion en asig y en doc hacia Dicta.
        @param mod la modalidad de la clase
        @param doc El docente que dictara la asignatura.
        @param asig La asignatura dictada por el docente.
        */
        Dicta(modalidad mod,Docente* doc, Asignatura* asig);
        Docente* getDocente();
        /**
        Elimina el puntero a Dicta de doc. Llama a deslinkear(this) en docente?
        */
        void deslinkearDocente();
        Asignatura* getAsignatura();
        modalidad getModalidad();
};

#endif