#ifndef IMENSAJE_H
#define IMENSAJE_H

#include <string>
#include <set>
#include "DtClase.h"
#include "DtMensaje.h"

class IMensaje{
    public:
        virtual void identificarse(std::string email, std::string contrasenia);
        virtual std::set<DtClase*> listarClases();
        virtual void elegirClase(std::string id);
        virtual std::set<DtMensaje*> listarMensajes();
        virtual void seleccionarMensaje(std::string idMensaje);
        virtual void textoenviar(std::string texto);
        virtual void confirmarEnvioMensaje(bool conf);
};

#endif