#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string> 
#include "usuario.h"
#include "asignatura.h"
#include "claseestudiante.h"
#include "clase.h"
#include <set>
#include "asistenciavivo.h"

class Asignatura;
class Clase;
// class ClaseEstudiante;

class Estudiante : public Usuario {
    private:
        std::string ci;
        std::set<ClaseEstudiante*> claseestudiantes;
        std::set<Asignatura*> asignaturas;


    public:
        std::string getCi();
        void setCi(std::string);
    //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

    //operaciones que hereda de usuario
        virtual std::set<Clase*> listarClases();//tiene metodo
        virtual std::set<Clase*> listarClasesVivo();
        virtual bool tieneAsignatura(Asignatura *a);
        virtual Clase* elegirClase(std::string id);
    //operaciones mismas de estudiante
        void eliminarAsignatura(Asignatura *a);
        std::set<Asignatura*> getAsignaturas();
        Asignatura *getAsignatura(std::string codigo);
        Estudiante(std::string nombre, std::string email, std::string contrasenia, std::string imagen, std::string ci);//constructor
        void addAsignatura(Asignatura *a);//se agrega para poder asignarle una asignatura al estudiante
        bool estaAsistiendo();
        void addClaseEstudiante(ClaseEstudiante* ce);
        void deslinkear(ClaseEstudiante* ce);
};



#endif