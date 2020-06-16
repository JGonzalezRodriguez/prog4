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
        virtual bool getConfi() = 0;
        virtual ~IAsignatura() {};
        //virtual ~IAsignatura() = 0;
        virtual void altaAsignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) = 0;
        virtual DtAsignatura* mostrarDatosAsignatura() = 0;
        virtual void confirmarAltaAsignatura(bool conf) = 0;

        //Agrego las operaciones correspondientes al caso de uso inscripcion a asignatura
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtAsignatura*> listarAsignaturasEstudiante() = 0;
        virtual void elegirAsignaturaEst(std::string codigo) = 0;
        virtual void confirmarInscripcionAsignatura(bool confi) = 0;
        virtual bool getIdentificado() = 0;
        virtual bool getCodigovalido() = 0;
};

#endif