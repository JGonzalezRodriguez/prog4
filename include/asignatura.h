#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include <set> 
#include "dicta.h"
#include "estudiante.h"
#include "clase.h"

class Asignatura {
    private:
        std::string nombre;
        std::string codigo;
        bool tieneteo;
        bool tieneprac;
        bool tienemon;
        std::set<Dicta*> dictas;
        std::set<Estudiante*> estudiantes;
        std::set<Clase*> clases;
    public:
        Asignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon);
        void addDocente(Dicta* dic);
        void addEstudiante(Estudiante* e);
        std::set<Estudiante*> getEstudiantes();
        Estudiante* getEstudiante(std::string CI);
        void addClase(Clase* c);
        std::set<Clase*> getClases();
        std::string getNombre();
        std::string getCodigo();
        bool tieneTeo();
        bool tienePrac();
        bool tieneMon();
};

#endif 