#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include <string>
#include <iostream>

class DtAsignatura{
    private:
        std::string nombre;
        std::string codigo;
    public:
        DtAsignatura(std::string nombre, std::string codigo);
        ~DtAsignatura();
        std::string getNombre();
        std::string getCodigo();
};

std::ostream& operator<< (std::ostream& os, DtAsignatura &b);
#endif