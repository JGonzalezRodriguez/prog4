#ifndef DTMONITOREO_H
#define DTMONITOREO_H

#include <set>
#include "DtClase.h"
#include "DtEstudiante.h"

class DtMonitoreo: public DtClase{
    private:
        std::set<DtEstudiante*> estudiantes;
    public:
        DtMonitoreo(std::set<DtEstudiante*> estudiantes);
        ~DtMonitoreo();
        std::set<DtEstudiante*> getEstudiantes();
        void setEstudiantes(std::set<DtEstudiante*> estudiantes);
};
#endif