#include "../include/DtMensaje.h"

DtMensaje::DtMensaje(std::string texto, DtFecha* fechayhora, std::set<DtMensaje*> respuestas){
    this->texto = texto;
    this->fechayhora = fechayhora;
    this->respuestas = respuestas;
}

DtMensaje::~DtMensaje(){}

std::string DtMensaje::getTexto(){
    return this->texto;
}

std::string DtMensaje::getFechaYHora(){
    return this->fechayhora;
}

std::string DtMensaje::getRespuestas(){
    return this->respuestas;
}
