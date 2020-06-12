#ifndef TEORICO_H
#define TEORICO_H
#include "clase.h"


class Teorico: public Clase{
    public:
        Teorico(string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};


#endif