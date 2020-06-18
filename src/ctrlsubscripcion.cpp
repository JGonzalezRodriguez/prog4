#include "../include/ctrlsubscripcion.h"

CtrlSubscripcion::CtrlSubscripcion(){}

CtrlSubscripcion *CtrlSubscripcion::instancia = NULL;

CtrlSubscripcion* CtrlSubscripcion::getInstancia() {
    if(instancia == NULL)
        instancia = new CtrlSubscripcion();
    return instancia;
}

bool CtrlSubscripcion::getIdentifico(){
    return this->identifico;
}

void CtrlSubscripcion::identificarse(std::string mail, std::string constrasenia) {
    Handlerusuarios *usuario = Handlerusuarios::getInstancia();
    if(usuario->identificarse(mail, constrasenia)){
        this->identifico = true;
        this->u = usuario->getUsuario(mail);
    }else{
        this->identifico = false;

    }
}

std::set<DtNotificacion*> CtrlSubscripcion::listarNotificaciones() {
    std::set<DtNotificacion*> x;
    return x;
}
void CtrlSubscripcion::eliminarNotificaciones() {

}

void CtrlSubscripcion::elegirModo() {
    
    this->u->elegirModo();

}
 
void CtrlSubscripcion::eliminarSubscripcion() {
    
}