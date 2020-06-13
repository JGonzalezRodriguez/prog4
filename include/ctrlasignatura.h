#ifndef CTRLASIGNATURA_H
#define CTRLASIGNATURA_H

#include "iasignatura.h"
// IMPORTAR ARCHIVO CON MODALIDAD ENUM.H ??
// OTRO CON DATATYPES
#include "dt/enums.h"
#include "dt/dtasignatura.h"
#include "dt/dtdocente.h"
#include "docente.h"
#include "estudiante.h"
#include "asignatura.h"
#include <set>
#include "handlerasignaturas.h"
#include "handlerusuarios.h"
#include "dicta.h"

class CtrlAsignatura : public IAsignatura {
    private:
        static CtrlAsignatura* instancia;
        modalidad mod;
        Docente* doc;
        Asignatura* asig;
        CtrlAsignatura();
    public:
        static CtrlAsignatura* getInstancia();
        std::set<DtAsignatura*> listarAsignaturas();
        void elegirAsignaturaAdmin(std::string codigo);
        std::set<DtDocente*> listarDocentes();
        void elegirdocente(modalidad modalidad, std::string emaildocente);
        void confirmarAsignacionDocenteAsignatura(bool confi);
        void confirmarEliminacionAsignatura(bool conf);   
};

#endif