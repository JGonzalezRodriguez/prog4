#ifndef DTASIGNATURAEXT_H
#define DTASIGNATURAEXT_H

#include "DtAsignatura.h"

class DtAsignaturaExt: public DtAsignatura{
    private:
        bool tieneteo;
        bool tieneprac;
        bool tienemon;
    public:
        DtAsignaturaExt(bool tieneteo, bool tieneprac, bool tienemon);
        ~DtAsignaturaExt();
        bool tieneTeo();
        bool tienePrac();
        bool tieneMon();
};
#endif