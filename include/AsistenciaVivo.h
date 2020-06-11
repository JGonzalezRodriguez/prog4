#ifndef ASISTENCIAVIVO_H
#define ASISTENCIAVIVO_H

// #include "Clase-estudiante.h"
// #include "DtFecha.h"

class AsistenciaVivo:
    private:
        DtFecha primeringresovivo;
        DtFecha ultimasalidavivo;
        bool estamirando;
        // Clase-estudiante* claseEstudiante; // es visible? probablemente no
    public:
        AsistenciaVivo(DtFecha primeringresovivo);
        ~AsistenciaVivo();
        void setEstaMirando(bool estamirando);
        void setUltimaSalidaVivo(DtFecha fecha);
        DtFecha getPrimerIngresoVivo();
        DtFecha getUltimaSalidaVivo();
        bool getEstaMirando();
        void finalizarVisualizacionVivo();