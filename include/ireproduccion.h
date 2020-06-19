#ifndef IREPRODUCCION_H
#define IREPRODUCCION_H

#include <string>
#include <set>

#include "dt/dtasignatura.h"
#include "dt/dtclase.h"
#include "dt/dtmensaje.h"

class IReproduccion {
    public:
        virtual bool identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtAsignatura*> listarAsignaturasEstudiante() = 0;
        virtual void elegirAsignaturaEst(std::string codigo) = 0;
        virtual std::set<DtClase*> listarClasesEstudiante() = 0;
        virtual void elegirClase(std::string id) = 0;
        virtual DtClase* mostrarDatosClase() = 0;
        virtual std::set<DtMensaje*> ListarMensajes() = 0;
        virtual void confirmarAsistenciaClaseEnVivo(bool confi) = 0;
        virtual bool estaAsistiendo() = 0;
        virtual ~IReproduccion() {};
        
};

#endif