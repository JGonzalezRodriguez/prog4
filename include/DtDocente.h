#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include "DtUsuario.h"
#include "enum.h"

class DtDocente: public DtUsuario{
    private:
        instituto instituto;
    public:
        DtDocente(instituto instituto);
        ~DtDocente();
        instituto getInstituto();
};
#endif
