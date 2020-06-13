#include "dt/dtfecha.h"

class Reloj {
    private:
        Reloj(DtFecha* fecha);
        static DtFecha* fecha;
    public:
        DtFecha* getFecha();
        void setFecha(DtFecha* fecha);
};