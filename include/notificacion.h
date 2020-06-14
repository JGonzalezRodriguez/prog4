#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include "mensaje.h"

class Asignatura;

class Notificacion{
    private:
        Mensaje* mensaje;
    public:
        Notificacion(Mensaje* mensaje);
        ~Notificacion();
        Mensaje* getMensaje();
        bool esDeAsignatura(Asignatura* a);
};

#endif