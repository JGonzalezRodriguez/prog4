#ifndef DTPROMASISTENCIA_H
#define DTPROMASISTENCIA_H

#include <string>
#include "dtclase.h"

class DtPromAsistencia{
    private:
        DtClase* clase;
        int horas;
        int mins;
    public:
        DtPromAsistencia(DtClase* clase, int horas, int mins);
        ~DtPromAsistencia();
        DtClase* getClase();
        int getHoras();
        int getMins();
};

std::ostream& operator<< (std::ostream& os, DtPromAsistencia &b);

#endif
