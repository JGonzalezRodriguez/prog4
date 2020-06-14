#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include <set> 
#include "dicta.h"
#include "clase.h"

class Estudiante;
class Dicta;
class Clase;

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
        /**
        Agrega una clase asociativa Dicta a la materia
        @param dic Ptr a Clase Asociativa Dicta
        */
        void addDocente(Dicta* dic);
        /**
         @param e puntero a estudiante
        */
        void addEstudiante(Estudiante* e);
        /**
         @return Col de Estudiantes que cursan la asignatura
        */
        std::set<Estudiante*> getEstudiantes();
        /**
         @param CI Cedula de identidad
        */
        Estudiante* getEstudiante(std::string CI);
        void addClase(Clase* c);
        /**
         @return Col de Clases
        */
        std::set<Clase*> getClases();
        /**
         @return Nombre de la Asignatura
        */
        std::string getNombre();
        /**
         @return El codigo de la Asignatura
        */
        std::string getCodigo();
        bool tieneTeo();
        bool tienePrac();
        bool tieneMon();
};

#endif 