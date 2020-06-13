#ifndef SUBSCRIPCION_H
#define SUBSCRIPCION_H

#include "usuario.h"
#include "mensaje.h"

class Subscripcion {
    public:
        /**
        Notifica al usuario u si cumple con los requisitos de su modo de subscripcion seleccionado.
        @param u Usuario a notificar.
        @param m Mensaje que genera la notificacion.
        */
        virtual void notificar(Usuario* u, Mensaje* m) = 0;
};

#endif