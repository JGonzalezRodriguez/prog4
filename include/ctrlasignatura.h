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
        ~CtrlAsignatura();

    public:
        static CtrlAsignatura* getInstancia();
        std::set<DtAsignatura*> listarAsignaturas();
        /**
        Ejecuta un find en el set de asignaturas del sistema. Guarda la asignatura resultante.
        @param codigo el valor para el cual se ejecuta el find.
        */
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
        /**
        En caso de ser true asocia el docente elegido a la asignatura elegida mediante un tipo asociativo dicta. El tipo asociativo contiene el campo modalidad con el valor de mod.
        @param confi booleano que decide si efectuar la asociacion o no.
        */
        void confirmarAsignacionDocenteAsignatura(bool confi);
        /**
        En caso de ser true debe destruir la asignatura actual y liberar toda la memoria asociada, ver Diagrama de Comunicacion.
        @param conf
        */
        void confirmarEliminacionAsignatura(bool conf); 
        void altaAsignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon);
        DtAsignatura* mostrarDatosAsignatura();
        void confirmarAltaAsignatura(bool conf);

};

#endif