#ifndef IREPRODUCCION_H
#define IREPRODUCCION_H

#include <string>
#include <set>

#include "dtasignatura.h"
#include "dtclase.h"
#include "dtmensaje.h"

class IReproduccion {
    private:
    IReproduccion();
    public:
    virtual void identificarse(std::string email, std::string contrasenia) = 0;
    virtual std::set<DtAsignatura*> listarAsignaturasEstudiante() = 0;
    virtual void elegirAsignaturaEst(std::string codigo) = 0;
    virtual std::set<DtClase*> listarClasesEstudiante() = 0;
    virtual void elegirClase(std::string id) = 0;
    virtual DtClase mostrarDatosClase() = 0;
    virtual std::set<DtMensaje*> ListarMensajes() = 0;

};

IReproduccion::~IReproduccion() {};

#endif