#ifndef ISUBSCRIPCION_H
#define ISUBSCRIPCION_H

#include <string>
#include <set>
#include "DtNotificacion.h"
#include "enum.h"

class ISubscripcion{
    public:
        virtual void identificarse(std::string email, std::string contrasenia);
        virtual std::set<DtNotificacion*> listarNotificaciones();
        virtual void eliminarNotificaciones();
        virtual void elegirModo(modoSubscripcion modo);
        virtual void eliminarSubscripcion();
};

#endif