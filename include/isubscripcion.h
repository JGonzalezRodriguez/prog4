#ifndef ISUBSCRIPCION_H
#define ISUBSCRIPCION_H

#include <string>
#include <set>
#include "dt/dtnotificacion.h"
#include "dt/enums.h"
#include "subscripcion.h"

class ISubscripcion {
    public:
        /**
        Identifica al usuario y lo recuerda como el usuario actual.
        */
        virtual void identificarse(std::string email, std::string contrasenia) = 0;
        /**
        @return Coleccion de notificaciones del usuario actual.
        */
        virtual std::set<DtNotificacion*> listarNotificaciones() = 0;
        /**
        Elimina las notificacion del usuario actual.
        */
        virtual void eliminarNotificaciones() = 0;
        /**
        Cambia el modo de subscripcion del usuario actual.
        @param modo El nuevo modo de subscripcion.
        */
        virtual void elegirModo(Subscripcion* modo) = 0;
        /**
        Elimina el puntero a subscripcion del usuario actual.
        */
        virtual void eliminarSubscripcion() = 0;
};

#endif