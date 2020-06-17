#ifndef PRACTICO_H
#define PRACTICO_H
#include "clase.h"
#include "dt/dtfecha.h"


class Practico: public Clase{

    public:
        Practico(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};

#endif