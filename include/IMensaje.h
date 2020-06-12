#ifndef IMENSAJE_H
#define IMENSAJE_H

#include <string>
#include <set>
#include "dt/dtclase.h"
#include "dt/dtmensaje.h"

class IMensaje{
    public:
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtClase*> listarClases() = 0;
        virtual void elegirClase(std::string id) = 0;
        virtual std::set<DtMensaje*> listarMensajes() = 0;
        virtual void seleccionarMensaje(std::string idMensaje) = 0;
        virtual void textoenviar(std::string texto) = 0;
        virtual void confirmarEnvioMensaje(bool conf) = 0;
};

#endif