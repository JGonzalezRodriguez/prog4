#ifndef PRACTICO_H
#define PRACTICO_H
#include "clase.h"
#include "dtfecha.h"


class Practico: public Clase{

    public:
        Practico(string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};


#endif