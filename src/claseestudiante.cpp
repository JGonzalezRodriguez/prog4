#include "../include/claseestudiante.h"

ClaseEstudiante::ClaseEstudiante(Clase* c, Estudiante* a) {
    Reloj* r = Reloj::getInstancia();
    this->avivo = new AsistenciaVivo(r->getFecha());
    this->est = a;
    this->c = c;
}

void ClaseEstudiante::finalizarVisualizacionesVivo() {
    avivo->finalizarVisualizacionVivo();
}

Estudiante* ClaseEstudiante::getEstudiante() {
    return this->est;
}

Clase* ClaseEstudiante::getClase() {
    return this->c;
}




AsistenciaVivo* ClaseEstudiante::getAvivo(){
    return this->avivo;
}