#ifndef CLASEESTUDIANTE_H
#define CLASEESTUDIANTE_H

//#include "clase.h"
#include "asistenciavivo.h"

class Clase;
class Estudiante;
class AsistenciaVivo;

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
        AsistenciaVivo* getavivo();

        
};

#endif 