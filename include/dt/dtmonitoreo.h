#ifndef DTMONITOREO_H
#define DTMONITOREO_H

#include <set>
#include "dtclase.h"
#include "dtestudiante.h"

class DtMonitoreo: public DtClase{
    private:
        std::set<DtEstudiante*> estudiantes;
    public:
        DtMonitoreo(std::set<DtEstudiante*> estudiantes, DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        ~DtMonitoreo();
        std::set<DtEstudiante*> getEstudiantes();
};
#endif