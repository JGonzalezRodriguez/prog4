#ifndef DOCENTE_H
#define DOCENTE_H
#include <string> 
#include "usuario.h"
#include "dicta.h"
#include "clase.h"
#include "dt/dtdocente.h"
#include <set>

class Asignatura;
class Dicta;

class Docente: public Usuario{
    private:
        instituto inst;
        std::set<Dicta*> dictas;
        std::set<Clase*> clases;
    
    public:
        instituto getInstituto();
        void setInstituto(instituto);
        //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

        //operaciones que hereda de usuario
        
        virtual std::set<Clase*> listarClases();
        virtual bool tieneAsignatura(Asignatura *a);
        virtual Clase* elegirClase(std::string id);
       
        //operaciones mismas de docente
        /**
        Genera un DtDocente de la instancia del objeto.
        @return Dt de la instancia
        */
        DtDocente* getDt();
        void addAsignatura(Dicta *dicta);
        void deslinkear(Dicta *dicta);
        std::set<Asignatura*> getAsignaturas();
        modalidad getModalidad(Asignatura *a);
        void addClase(Clase *c);
        std::set<Clase*> getClasesEnVivo();
        Clase *getClase(std::string id);
        Asignatura *getAsignatura(std::string codigo);
        Docente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto instituto);
        std::set<Clase*> getClasesFinalizadas();
};
#endif