#include "dt/dtfecha.h"

// auspiciado por rolex prri
class Reloj {
    private:
        Reloj(DtFecha* fecha);
        DtFecha* fecha;
        static Reloj* instancia;
    public:

        static Reloj* getInstancia();
        /**
        @return puntero a DtFecha con la fecha actual.
        */
        DtFecha* getFecha();

        /**
        Settea la fecha global
        @param fecha ptr a DtFecha con la fecha actual.
        */
        void setFecha(DtFecha* fecha);
};