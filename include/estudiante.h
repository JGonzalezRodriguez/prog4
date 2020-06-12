#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string> 
#include "usuario.h"
#include "claseestudiante.h"
#include <set>



class Estudiante: public Usuario{
    private:
        string ci;
        std::set<Claseestudiante*> claseestudiantes;
        std::set<Asignatura*> asignaturas;


    public:
        string getCi();
        void setCi(string);
    //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

    //operaciones que hereda de usuario
        virtual std::set<Clase*> listarClases();//tiene metodo
        virtual bool tieneAsignatura(Asignatura *a);
    //operaciones mismas de estudiante
        void eliminarAsignatura(Asignatura *a);
        std::set<Asignatura*> getAsignaturas();
        Asignatura *getAsignatura(string codigo);
        Estudiante(string nombre, string email, string contrasenia, string imagen, string ci);//constructor
};



#endif