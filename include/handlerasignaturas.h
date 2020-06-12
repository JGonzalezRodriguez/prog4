#ifndef HANDLERASIGNATURAS_H
#define HANDLERASIGNATURAS_H


#include <map>
#include "asignatura.h"

class HandlerAsignaturas {
    private:
        static HandlerAsignaturas* instancia;
        HandlerAsignaturas();
        std::map<string, Asignatura*> mapasignaturas;
    public:
        static HandlerAsignaturas* getInstancia();
        std::map<string, Asignatura*> get();
        Asignatura* find(string codigo);
        void remove(Asignatura* a);
}

#endif 