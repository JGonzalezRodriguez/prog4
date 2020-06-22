#ifndef TEORICO_H
#define TEORICO_H
#include "clase.h"


class Teorico: public Clase{
    public:
        Teorico(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
        ~Teorico();
};


#endif