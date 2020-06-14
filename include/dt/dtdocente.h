#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include "dtusuario.h"
#include "enums.h"

class DtDocente: public DtUsuario{
    private:
        instituto inst;
    public:
        DtDocente(instituto instituto, std::string nombre, std::string email, std::string imagen, std::string contrasenia);
        ~DtDocente();
        instituto getInstituto();
};
#endif
