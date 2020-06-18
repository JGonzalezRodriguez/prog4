#include "../include/monitoreo.h"

void Monitoreo::setEstudiantes(std::set<Estudiante*> ColMonitoreo){

}

Monitoreo::Monitoreo(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc):Clase(nombre, fecha, asignatura, doc){

}

Monitoreo::~Monitoreo(){
}