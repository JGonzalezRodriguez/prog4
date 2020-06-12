#include <map>
#include "asignatura.h"

class HandlerAsignaturas {
    private:
        static HandlerAsignaturas* instancia;
        HandlerAsignaturas();
        std::map<Asignatura> mapasignaturas;
    public:
        HandlerAsignaturas getInstancia();
        std::map<Asignatura> get();
        Asignatura find(string codigo);
        void remove(Asignatura a);
}