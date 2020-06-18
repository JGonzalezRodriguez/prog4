#ifndef DTTIEMPOASIGNATURA_H
#define DTTIEMPOASIGNATURA_H

#include <string>
#include <iostream>
//#include "dtfecha.h"

class DtTiempoAsignatura{
    private:
        std::string asignatura;
        int horas;
        int mins;
    public:
        DtTiempoAsignatura(std::string asignatura, int horas, int mins);
        ~DtTiempoAsignatura();
        std::string getAsignatura();
        int getHoras();
        int getMins();
};

std::ostream& operator<< (std::ostream& os, DtTiempoAsignatura &b);

#endif
