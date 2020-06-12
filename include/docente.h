#ifndef DOCENTE_H
#define DOCENTE_H
#include <string> 
#include "usuario.h"
#include "dicta.h"
#include "clase.h"
#include <set>



class Docente: public Usuario{
    private:
        instituto instituto;
        std::set<Dicta*> dictas;
        std::set<Clase*> clases;
    
    public:
        instituto getInstituto();
        void setInstituto(instituto);
        //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

        //operaciones que hereda de usuario
        
        virtual std::set<Clase*> listarClases();
        virtual bool tieneAsignatura(Asignatura *a);
       
        //operaciones mismas de docente
        void addAsignatura(Dicta *dicta);
        void deslinkear(Dicta *dicta);
        std::set<Asignatura*> getAsignaturas();
        modalidad getModalidad(Asignatura *a);
        void addClase(Clase *c);
        std::set<Clase*> getClasesEnVivo();
        Clase *getClase(string id);
        Asignatura *getAsignatura(string codigo);
        Docente(string nombre, string email, string contrasenia, string imagen, instituto instituto);
        
       
};
#endif