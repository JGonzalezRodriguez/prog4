#include "../include/DtMonitoreo.h"

DtMonitoreo::DtMonitoreo(std::set<DtEstudiante*> estudiantes, DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url,
    DtDocente* docente):DtClase(fechayhoracomienzo, fechayhorafinal, envivo, id, nombre, url, docente){
        //primero ejecuta el constructor de DtClase
        this->estudiantes = estudiantes;
}

DtMonitoreo::~DtMonitoreo(){}

std::set<DtEstudiante*> DtMonitoreo::getEstudiantes(){
    return this->estudiantes;
}

void DtMonitoreo:: setEstudiantes(std::set<DtEstudiante*> estudiantes){
    this->estudiantes = estudiantes;
}