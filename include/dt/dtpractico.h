#ifndef DTPRACTICO_H
#define DTPRACTICO_H

#include "dtclase.h"

class DtPractico: public DtClase{
    private:
        //TODO: Nada? Really? (en el DCD no hay nada)
    public:
        DtPractico(DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        ~DtPractico();
};
#endif