#ifndef HANDLERASIGNATURAS_H
#define HANDLERASIGNATURAS_H


#include <map>
#include "asignatura.h"

class HandlerAsignaturas {
    private:
        static HandlerAsignaturas* instancia;
        HandlerAsignaturas();
        std::map<Asignatura> mapasignaturas;
    public:
        static HandlerAsignaturas getInstancia();
        std::map<Asignatura> get();
        Asignatura find(string codigo);
        void remove(Asignatura a);
}

#endif 