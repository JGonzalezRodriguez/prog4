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
        /**
        @return Coleccion de docentes que pueden dictar la asignatura
        Debe crear los DtDocente a partir de una coleccion de docentes.
        Filtra los docentes que ya dictan la asignatura?
        */
        std::set<DtDocente*> listarDocentes();
        /**
        Elige el docente para dictar la asignatura.
        @param mod la modalidad que dictara el docente.
        @param emaildocente el email del docente.
        */
        void elegirdocente(modalidad mod, std::string emaildocente);
        void confirmarAsignacionDocenteAsignatura(bool confi);
        /**
        Debe destruir la asignatura actual y liberar toda la memoria asociada, ver Diagrama de Comunicacion. 
        */
        void confirmarEliminacionAsignatura(bool conf); 
};

#endif