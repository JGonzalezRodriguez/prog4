#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include "Mensaje.h"

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