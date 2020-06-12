#ifndef ICLASE_H
#define ICLASE_H

#include <string>
#include <set>
#include "modalidad.h"
#include "dtfecha.h"
#include "dtestudiante.h"
#include "dtclase.h"


class IClase {
    private:
    IClase();
    public:
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtAsignatura*> listarAsignaturasDocente() = 0;
        virtual void inicioDeClase(std::string codigoasignatura, std::string nombre, DtFecha fecha) = 0;
        virtual modalidad getModalidad() = 0;
        virtual std::set<DtEstudiante*> listarEstudiantesHabilitados() = 0;
        virtual void elegirEstudiante(std::string ci) = 0;
        virtual DtClase mostrarDatos() = 0;
        virtual void confirmarInicioDeClase(bool conf) = 0;
        virtual std::set<DtClase*> listarClasesEnVivo() = 0;
        virtual void elegirClase(std::string id) = 0;
        virtual DtClase mostrarClase() = 0;
        virtual void confirmarFinalizacionDeClase(bool conf) = 0;
        virtual void elegirAsignaturaDoc(codigo: string) = 0;
        virtual std::set<DtClase*> listarClasesDocente() = 0;
};

IClase::~IClase() {};

#endif