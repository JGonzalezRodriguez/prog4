#include "../include/ctrlsubscripcion.h"
#include <iostream>

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
        throw std::invalid_argument("Las credenciales que ingreso no son correctas");
    }
}

std::set<DtNotificacion*> CtrlSubscripcion::listarNotificaciones() {
    std::set<Notificacion*> colnot = u->listarNotificaciones();
    std::set<DtNotificacion*> coldtnot;
    for (std::set<Notificacion*>::iterator it=colnot.begin(); it!=colnot.end(); ++it) {
        Notificacion* noti = *it;
        DtFecha* f = noti->getMensaje()->getFechaYHoraEnviado();
        std::string nombreclase = noti->getMensaje()->getClase()->getNombre();
        std::string idclase = noti->getMensaje()->getClase()->getId();
        DtAsignatura* asig = new DtAsignatura(noti->getMensaje()->getAsignatura()->getNombre(), noti->getMensaje()->getAsignatura()->getCodigo());
        DtNotificacion* dtnoti = new DtNotificacion(f, nombreclase, idclase, asig);
        coldtnot.insert(dtnoti);;
    }
    return coldtnot;
}
void CtrlSubscripcion::eliminarNotificaciones() {
    u->eliminarNotificaciones();
}

void CtrlSubscripcion::elegirModo() {
    this->u->elegirModo();
    Handlerusuarios *subscribir = Handlerusuarios::getInstancia();
    subscribir->addSubscripto(this->u);

}
 
void CtrlSubscripcion::eliminarSubscripcion() {
    
}