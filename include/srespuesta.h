#ifndef SRESPUESTA_H
#define SRESPUESTA_H

#include "subscripcion.h"

class SRespuesta : public Subscripcion {
    private:
        static SRespuesta* instancia;
        SRespuesta();
    public:
        static SRespuesta* getInstancia();
        void notificar(Usuario* u, Mensaje* m); // si tira error poner virtual aca
};

#endif