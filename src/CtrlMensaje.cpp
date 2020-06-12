#include "../include/CtrlMensaje.h"

CtrlMensaje* CtrlMensaje::instancia = NULL;

CtrlMensaje::CtrlMensaje(){}

CtrlMensaje::~CtrlMensaje(){}

CtrlMensaje* CtrlMensaje::getInstancia(){
    if(CtrlMensaje::instancia == NULL){
        CtrlMensaje::instancia = new CtrlMensaje();
    }
    return CtrlMensaje::instancia;
}

Usuario* CtrlMensaje::getUsuario(){
    return this->u;
}

Clase* CtrlMensaje::getClase(){
    return this->c;
}

Mensaje* CtrlMensaje::getMensaje(){
    return this->m;
}

void CtrlMensaje::setUsuario(Usuario* u){
    this->u = u;
}

void CtrlMensaje::setClase(Clase* c){
    this->c = c;
}

void CtrlMensaje::setMensaje(Mensaje* m){
    this->m = m;
}

void CtrlMensaje::identificarse(std::string mail, std::string contrasenia){
    //TODO
}

std::set<DtClase*> CtrlMensaje::listarClases(){
    //TODO
}

void CtrlMensaje::elegirClase(std::string id){
    //TODO
}

std::set<DtMensaje*> CtrlMensaje::listarMensajes(){
    //TODO
}

void CtrlMensaje::seleccionarMensaje(std::string idMensaje){
    //TODO
}

void CtrlMensaje::textoEnviar(std::string texto){
    //TODO
}

void CtrlMensaje::confirmarEnvioMensaje(bool conf){
    //TODO
}