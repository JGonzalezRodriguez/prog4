#ifndef DTASIGNATURAEXT_H
#define DTASIGNATURAEXT_H

#include "dtasignatura.h"

class DtAsignaturaExt: public DtAsignatura{
    private:
        bool tieneteo;
        bool tieneprac;
        bool tienemon;
    public:
        DtAsignaturaExt(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon);
        ~DtAsignaturaExt();
        bool tieneTeo();
        bool tienePrac();
        bool tieneMon();
};
#endif