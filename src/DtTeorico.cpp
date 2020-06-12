#include "../include/DtTeorico.h"

DtTeorico::DtTeorico(int cantasistentes, DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url,
    DtDocente* docente):DtClase(fechayhoracomienzo, fechayhorafinal, envivo, id, nombre, url, docente){
        //primero ejecuta el constructor de DtClase
        this->cantasistentes = cantasistentes;
}

DtTeorico::~DtTeorico(){}

int DtTeorico::getCantAsistentes(){
    return this->cantasistentes;
}

void DtTeorico::setCantAsistentes(int cantasistentes){
    this->cantasistentes = cantasistentes;
}
