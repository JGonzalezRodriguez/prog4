#include "../include/claseestudiante.h"

ClaseEstudiante::ClaseEstudiante(Clase* c, Estudiante* a) {

}

void ClaseEstudiante::finalizarVisualizacionesVivo() {

}

Estudiante* ClaseEstudiante::getEstudiante() {
    return this->est;
}

Clase* ClaseEstudiante::getClase() {
    return this->c;
}