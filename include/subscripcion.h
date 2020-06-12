#ifndef SUBSCRIPCION_H
#define SUBSCRIPCION_H

#include "usuario.h"
#include "mensaje.h"

class Subscripcion {
    public:
        virtual void notificar(Usuario u, Mensaje m) = 0;
}

#endif