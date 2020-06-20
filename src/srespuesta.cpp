#include "../include/srespuesta.h"

SRespuesta* SRespuesta::instancia = NULL;

SRespuesta::SRespuesta(){}

SRespuesta *SRespuesta::getInstancia(){
    if(instancia == NULL)
        instancia = new SRespuesta();
    return instancia;
}

void SRespuesta::notificar(Usuario* u, Mensaje* m) {
    if(!m->esRaiz()){
        Usuario *uaux = m->getPadre()->getAutor();
        if(u == uaux){
            Notificacion *noti = new Notificacion(m);
            u->addNotificacion(noti);
        }
    }

}