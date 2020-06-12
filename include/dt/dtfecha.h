#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int min;
    public:
        DtFecha(int dia, int mes, int anio, int hora, int min);
        ~DtFecha();
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMin();
};
#endif

