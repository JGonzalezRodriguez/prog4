#include "../include/fabrica.h"

class IAsignatura;

Fabrica *Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica *Fabrica::getInstancia(){
    if(instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

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