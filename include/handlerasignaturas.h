#ifndef HANDLERASIGNATURAS_H
#define HANDLERASIGNATURAS_H

#include <map>
#include <string>
#include "asignatura.h"

class HandlerAsignaturas {
    private:
        static HandlerAsignaturas* instancia;
        HandlerAsignaturas();
        std::map<std::string, Asignatura*> mapasignaturas;
    public:
        static HandlerAsignaturas* getInstancia();
        /**
        @return un map de Asignaturas del sistema
        */
        std::map<std::string, Asignatura*> get();
        Asignatura* find(std::string codigo);
        void remove(Asignatura* a);
        void add(Asignatura* a);
};

#endif