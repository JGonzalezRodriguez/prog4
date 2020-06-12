#ifndef CLASEESTUDIANTE_H
#define CLASEESTUDIANTE_H

#include "clase.h"
#include "estudiante.h"
#include "asistenciaVivo.h"

class ClaseEstudiante {
    private:
        Clase* c;
        Estudiante* est;
        asistenciaVivo * avivo;
    public:
        ClaseEstudiante(Clase c, Estudiante a);
        void finalizarVisualizacionesVivo();
        Estudiante getEstudiante();
        Clase getClase();
}

#endif 