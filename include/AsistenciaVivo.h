#ifndef ASISTENCIAVIVO_H
#define ASISTENCIAVIVO_H

#include "claseestudiante.h"
#include "dt/dtfecha.h"

class AsistenciaVivo{
    private:
        DtFecha* primeringresovivo;
        DtFecha* ultimasalidavivo;
        bool estamirando;
    public:
        AsistenciaVivo(DtFecha* primeringresovivo);
        ~AsistenciaVivo();
        void setEstaMirando(bool estamirando);
        void setUltimaSalidaVivo(DtFecha* fecha);
        DtFecha* getPrimerIngresoVivo();
        DtFecha* getUltimaSalidaVivo();
        bool getEstaMirando();
        void finalizarVisualizacionVivo();
};

#endif