#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include <string>
#include "dtusuario.h"

class DtEstudiante: public DtUsuario{
    private:
        std::string ci;
    public:
        DtEstudiante(std::string ci, std::string nombre, std::string email, std::string imagen, std::string contrasenia);
        ~DtEstudiante();
        std::string getCi();
};
#endif