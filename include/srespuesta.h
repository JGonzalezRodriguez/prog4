#ifndef SRESPUESTA_H
#define SRESPUESTA_H

#include "subscripcion.h"

class SRespuesta {
    private:
        static SRespuesta* instancia;
        SRespuesta();
    public:
        SRespuesta getInstancia();
        void notificar(Usuario u, Mensaje m);
}

#endif