#ifndef DTTIEMPOASIGNATURA_H
#define DTTIEMPOASIGNATURA_H

#include <string>
#include "dtfecha"

class DtTiempoAsignatura{
    private:
        std::string asignatura;
        DtFecha* tiempo;
    public:
        DtTiempoAsignatura(std::string asignatura, DtFecha* tiempo);
        ~DtTiempoAsignatura();
        std::string getAsignatura();
        DtFecha* getTiempo();
};
#endif
