#include "../include/srespuesta.h"

SRespuesta* SRespuesta::instancia = NULL;

SRespuesta::SRespuesta(){}

SRespuesta *SRespuesta::getInstancia(){
    if(instancia == NULL)
        instancia = new SRespuesta();
    return instancia;
}

void SRespuesta::notificar(Usuario* u, Mensaje* m) {

}