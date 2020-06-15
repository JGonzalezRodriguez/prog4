#ifndef IASIGNATURA_H
#define IASIGNATURA_H

#include <set>
#include <map>
#include <string>
#include "dt/dtasignatura.h"
#include "dt/dtdocente.h"
#include "dt/enums.h"

class IAsignatura {
    public:
        virtual std::map<std::string, DtAsignatura*> listarAsignaturas() = 0;
        virtual void elegirAsignaturaAdmin(std::string codigo) = 0;
        virtual std::set<DtDocente*> listarDocentes() = 0;
        virtual void elegirdocente(modalidad modalidad, std::string emaildocente) = 0;
        virtual void confirmarAsignacionDocenteAsignatura(bool confi) = 0;
        virtual void confirmarEliminacionAsignatura(bool conf) = 0;
        virtual ~IAsignatura() {};
};

#endif