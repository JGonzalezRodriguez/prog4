#include "../include/ctrlsubscripcion.h"



CtrlSubscripcion* CtrlSubscripcion::getInstancia() {
    return NULL;
}

bool CtrlSubscripcion::getIdentifico(){
    return this->identifico;
}

void CtrlSubscripcion::identificarse(std::string mail, std::string constrasenia) {
    //Handlerusuarios *u = Handlerusuarios::getInstancia();


}

std::set<DtNotificacion*> CtrlSubscripcion::listarNotificaciones() {
    std::set<DtNotificacion*> x;
    return x;
}
void CtrlSubscripcion::eliminarNotificaciones() {

}

void CtrlSubscripcion::elegirModo() {

}
 
void CtrlSubscripcion::eliminarSubscripcion() {
    
}