#include "../include/dt/dtmensaje.h"

DtMensaje::DtMensaje(std::string texto, DtFecha* fechayhora, std::set<DtMensaje*> respuestas){
    this->texto = texto;
    this->fechayhora = fechayhora;
    this->respuestas = respuestas;
}

DtMensaje::~DtMensaje(){}

std::string DtMensaje::getTexto(){
    return this->texto;
}

DtFecha* DtMensaje::getFechaYHora(){
    return this->fechayhora;
}

std::set<DtMensaje*> DtMensaje::getRespuestas(){
    return this->respuestas;
}
