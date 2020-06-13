#ifndef CLASEESTUDIANTE_H
#define CLASEESTUDIANTE_H

#include "clase.h"
#include "estudiante.h"
#include "asistenciavivo.h"

class ClaseEstudiante {
    private:
        Clase* c;
        Estudiante* est;
        AsistenciaVivo * avivo;
    public:
        ClaseEstudiante(Clase* c, Estudiante* a);
        /**
        Guarda la fecha actual como DtFecha en avivo->ultimasalidavivo
        */
        void finalizarVisualizacionesVivo();
        Estudiante* getEstudiante();
        Clase* getClase();
};

#endif 