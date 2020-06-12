#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include <string>

class DtAsignatura{
    private:
        std::string nombre;
        std::string codigo;
    public:
        DtAsignatura(std::string nombre, std::string codigo);
        ~DtAsignatura();
        std::string getNombre();
        std::string getCodigo();
        void setNombre(std::string nombre);
        void setCodigo(std::string codigo);
};
#endif