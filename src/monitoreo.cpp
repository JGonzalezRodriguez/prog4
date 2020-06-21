#include "../include/monitoreo.h"

void Monitoreo::setEstudiantes(std::set<Estudiante*> ColMonitoreo){
    this->habilitados = ColMonitoreo;
}

bool Monitoreo::estaHabilitado(Estudiante* est) {
    std::set<Estudiante*>::iterator it;
    for (it = habilitados.begin(); it != habilitados.end(); it++) {
        if ((*it) == est) {
            printf("El estudiante esta habilitado");
            return true;
        }
    }
    return false;
}

Monitoreo::Monitoreo(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc):Clase(nombre, fecha, asignatura, doc){

}

Monitoreo::~Monitoreo(){
}