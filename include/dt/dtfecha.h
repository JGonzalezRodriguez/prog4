#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int min;
    public:
        DtFecha(int dia, int mes, int anio, int hora, int min);
        DtFecha(DtFecha* f);
        ~DtFecha();
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMin();
};

std::ostream& operator<< (std::ostream& os, DtFecha &b);
#endif

