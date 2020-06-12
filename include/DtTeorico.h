#ifndef DTTEORICO_H
#define DTTEORICO_H

#include "DtClase.h"

class DtTeorico: public DtClase{
    private:
        int cantasistentes;
    public:
        DtTeorico(int cantasistentes);
        ~DtTeorico();
        int getCantAsistentes();
        void setCantAsistentes(int cantasistentes);
};
#endif