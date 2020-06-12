#ifndef ISUBSCRIPCION_H
#define ISUBSCRIPCION_H

#include <string>
#include <set>
#include "dt/dtnotificacion.h"
#include "enums.h"

class ISubscripcion{
    public:
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        virtual std::set<DtNotificacion*> listarNotificaciones() = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual void elegirModo(modoSubscripcion modo) = 0;
        virtual void eliminarSubscripcion() = 0;
};

#endif