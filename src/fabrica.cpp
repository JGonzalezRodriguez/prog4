#include "../include/fabrica.h"

class IAsignatura;

IAsignatura* Fabrica::getIAsignatura() {
    return CtrlAsignatura::getInstancia();
}
IClase* Fabrica::getIClase() {
    return CtrlClase::getInstancia();
}
IMensaje* Fabrica::getIMensaje() {
    return CtrlMensaje::getInstancia(); 
}
IReproduccion* Fabrica::getIReproduccion() {
    return CtrlReproduccion::getInstancia();  
}
ISubscripcion* Fabrica::getISubscripcion() {
    return CtrlSubscripcion::getInstancia();  
}
IUsuario* Fabrica::getIUsuario() {
    return CtrlUsuario::getInstancia(); 
}