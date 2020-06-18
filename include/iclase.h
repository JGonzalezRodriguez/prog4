#ifndef ICLASE_H
#define ICLASE_H

#include <string>
#include <set>
#include "dt/enums.h"
#include "dt/dtfecha.h"
#include "dt/dtestudiante.h"
#include "dt/dtclase.h"
#include "dt/dtpreview.h"
#include "dt/dttiempoasignatura.h"


class IClase {
    public:
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtAsignatura*> listarAsignaturasDocente() = 0;
        virtual void inicioDeClase(std::string codigoasignatura, std::string nombre) = 0;
        virtual modalidad getModalidad() = 0;
        virtual std::set<DtEstudiante*> listarEstudiantesHabilitados() = 0;
        virtual void elegirEstudiante(std::string ci) = 0;
        virtual DtPreview* mostrarDatos() = 0;
        virtual void confirmarInicioDeClase(bool conf) = 0;
        virtual std::set<DtPreview*> listarClasesEnVivo() = 0;
        virtual void elegirClase(std::string id) = 0;
        virtual DtPreview* mostrarClase() = 0;
        virtual void confirmarFinalizacionDeClase(bool conf) = 0;
        virtual void elegirAsignaturaDoc(std::string codigo) = 0;
        virtual std::set<DtClase*> listarClasesDocente() = 0;
        virtual ~IClase() {};
        virtual std::set<DtTiempoAsignatura*> tiempoDictadoClases() = 0;
};

#endif