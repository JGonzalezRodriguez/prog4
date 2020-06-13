#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string> 
#include "usuario.h"
#include "claseestudiante.h"
#include <set>



class Estudiante: public Usuario{
    private:
        std::string ci;
        std::set<Claseestudiante*> claseestudiantes;
        std::set<Asignatura*> asignaturas;


    public:
        std::string getCi();
        void setCi(std::string);
    //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

    //operaciones que hereda de usuario
        virtual std::set<Clase*> listarClases();//tiene metodo
        virtual bool tieneAsignatura(Asignatura *a);
    //operaciones mismas de estudiante
        void eliminarAsignatura(Asignatura *a);
        std::set<Asignatura*> getAsignaturas();
        Asignatura *getAsignatura(std::string codigo);
        Estudiante(std::string nombre, std::string email, std::string contrasenia, std::string imagen, std::string ci);//constructor
};



#endif