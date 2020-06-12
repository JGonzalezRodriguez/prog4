#include "../include/AsistenciaVivo.h"

AsistenciaVivo::AsistenciaVivo(DtFecha* primeringresovivo){
    this->primeringresovivo = primeringresovivo;
    this->estamirando = true;
}

AsistenciaVivo::~AsistenciaVivo(){}

AsistenciaVivo::setEstaMirando(bool estamirando){
    this->estamirando = estamirando;
}

AsistenciaVivo::setUltimaSalidaVivo(DtFecha* fecha){
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
    // TODO
}


