#ifndef SRESPUESTA_H
#define SRESPUESTA_H

#include "subscripcion.h"


class SRespuesta : public Subscripcion {
    private:
        static SRespuesta* instancia;
        SRespuesta();
    public:
        static SRespuesta* getInstancia();
        /**
        Notifica al usuario si el mensaje es una respuesta a un mensaje suyo
        @param u Usuario a ser notificado
        @param m Mensaje que genero la notificacion
        */
        void notificar(Usuario* u, Mensaje* m); // si tira error poner virtual aca
};

#endif