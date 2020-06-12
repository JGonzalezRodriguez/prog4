#ifndef DTTIEMPOASIGNATURA_H
#define DTTIEMPOASIGNATURA_H

#include <string>
#include "DtFecha"

class DtTiempoAsignatura{
    private:
        std::string asignatura; //Es el codigo, no? el nombre del atributo es poco descriptivo TODO: Cambiar?
        DtFecha* tiempo;
    public:
        DtTiempoAsignatura(std::string asignatura, DtFecha* tiempo);
        ~DtTiempoAsignatura();
        std::string getAsignatura();
        DtFecha* getTiempo();
};
#endif
