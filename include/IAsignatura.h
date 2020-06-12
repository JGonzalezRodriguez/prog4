#ifndef IASIGNATURA_H
#define IASIGNATURA_H

#include <set>
#include <string>
//#include "DtAsignatura.h"
//#include "DtDocente.h"
//#include "modalidad.h"

class IAsignatura {
    private:
    IAsignatura();
    public:
    virtual std::set<DtAsignatura> listarAsignaturas() = 0;
    virtual void elegirAsignaturaAdmin(std::string codigo) = 0;
    virtual std::set<DtDocente> listarDocentes() = 0;
    virtual void elegirdocente(modalidad modalidad,std::string emaildocente) = 0;
    virtual void confirmarAsignacionDocenteAsignatura(bool confi)= 0;
    virtual void confirmarEliminacionAsignatura(bool conf) = 0;
};

IAsignatura::~IAsignatura() { };

#endif