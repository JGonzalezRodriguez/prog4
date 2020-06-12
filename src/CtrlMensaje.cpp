#include "../include/CtrlMensaje.h"

CtrlMensaje* CtrlMensaje::instancia = NULL;

CtrlMensaje::CtrlMensaje(){
    this->u = NULL;
    this->c = NULL;
    this->m = NULL;
}

CtrlMensaje::~CtrlMensaje(){}

CtrlMensaje* CtrlMensaje::getInstancia(){
    if(instancia == NULL){
        instancia = new CtrlMensaje();
    }
    return instancia;
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
    std::set<DtClase*> x;
    return x;
}

void CtrlMensaje::elegirClase(std::string id){
    //TODO
}

std::set<DtMensaje*> CtrlMensaje::listarMensajes(){
    //TODO
    std::set<DtMensaje*> x;
    return x;
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