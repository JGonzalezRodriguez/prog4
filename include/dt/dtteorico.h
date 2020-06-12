#ifndef DTTEORICO_H
#define DTTEORICO_H

#include "dtclase.h"

class DtTeorico: public DtClase{
    private:
        int cantasistentes;
    public:
        DtTeorico(int cantasistentes, DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        ~DtTeorico();
        int getCantAsistentes();
};
#endif