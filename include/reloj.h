#include "dt/dtfecha.h"

class Reloj {
    private:
        Reloj(DtFecha* fecha);
        static DtFecha* fecha;
        static Reloj* instancia;
    public:

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