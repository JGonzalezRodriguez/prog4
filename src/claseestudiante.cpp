#include "../include/claseestudiante.h"

ClaseEstudiante::ClaseEstudiante(Clase* c, Estudiante* a) {
    Reloj* r = Reloj::getInstancia();
    DtFecha* dtf = new DtFecha(r->getFecha());
    this->avivo = new AsistenciaVivo(dtf);
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

AsistenciaVivo* ClaseEstudiante::getavivo(){
    return this->avivo;
}
 
void ClaseEstudiante::asistirVivo(){
    this->avivo->setEstaMirando(true);
}

ClaseEstudiante::~ClaseEstudiante() {
    if (avivo != NULL) {
        delete avivo;
    }
}