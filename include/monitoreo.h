#ifndef MONITOREO_H
#define MONITOREO_H
#include "estudiante.h"
#include "clase.h"
#include "dt/dtfecha.h"
#include "asignatura.h"
#include <set>

class Monitoreo: public Clase{
    private:
        std::set<Estudiante*> habilitados;//recordar que el maximo del set es 15, chequearlo con un if al momento de implementar
    public:
        void setEstudiantes(std::set<Estudiante*> ColMonitoreo);
        Monitoreo(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};

#endif