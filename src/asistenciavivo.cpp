#include "../include/asistenciavivo.h"

AsistenciaVivo::AsistenciaVivo(DtFecha* primeringresovivo){
    this->primeringresovivo = primeringresovivo;
    this->estamirando = true;
}

AsistenciaVivo::~AsistenciaVivo(){}

void AsistenciaVivo::setEstaMirando(bool estamirando){
    this->estamirando = estamirando;
}

void AsistenciaVivo::setUltimaSalidaVivo(DtFecha* fecha){
    this->ultimasalidavivo = fecha;
}

DtFecha* AsistenciaVivo::getPrimerIngresoVivo(){
    return this->primeringresovivo;
}

DtFecha* AsistenciaVivo::getUltimaSalidaVivo(){
    return this->ultimasalidavivo;
}

bool AsistenciaVivo::getEstaMirando(){
    return this->estamirando;
}

void AsistenciaVivo::finalizarVisualizacionVivo(){
    Reloj* r = Reloj::getInstancia();
    DtFecha* dtf = new DtFecha(r->getFecha());
    ultimasalidavivo = dtf;
    estamirando = false;
}


