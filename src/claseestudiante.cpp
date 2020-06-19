#include "../include/claseestudiante.h"

ClaseEstudiante::ClaseEstudiante(Clase* c, Estudiante* a) {

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

AsistenciaVivo* ClaseEstudiante::getavivo() {
    return this->avivo;
}