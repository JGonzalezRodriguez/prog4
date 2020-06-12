#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include <set> 
#include "dicta.h"
#include "estudiante.h"

class Asignatura {
    private:
        string nombre;
        string codigo;
        bool tieneteo;
        bool tieneprac;
        bool tienemon;
        std::set<Dicta*> dictas;
        std::set<Estudiante*> estudiantes;
        std::set<Clase*> clases;
    public:
        Asignatura(string nombre, string codigo, bool tieneteo, bool tieneprac, bool tienemon);
        void addDocente(Dicta* dic);
        void addEstudiante(Estudiante* e);
        std::set<Estudiante*> getEstudiantes();
        Estudiante* getEstudiante(string CI);
        void addClase(Clase* c);
        std::set<Clase*> getClases();
}

#endif 