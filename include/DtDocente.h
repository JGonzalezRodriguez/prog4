#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include "DtUsuario.h"
#include "enum.h"

class DtDocente: public DtUsuario{
    private:
        instituto instituto;
    public:
        DtDocente(instituto instituto, std::string nombre, std::string email, std::string imagen, std::string contrasenia);
        ~DtDocente();
        instituto getInstituto();
};
#endif
