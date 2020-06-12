#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include "DtUsuario.h"

class DtEstudiante: public DtUsuario{
    private:
        std::string ci;
    public:
        DtEstudiante(std::string ci);
        ~DtEstudiante();
        std::string getCi();
};
#endif