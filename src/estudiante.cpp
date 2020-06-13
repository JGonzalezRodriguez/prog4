#include "../include/estudiante.h"

string Estudiante::getCi(){
    return this->ci;
}
void Estudiante::setCi(string ci){
    this->ci = ci;
}

//operaciones que hereda de usuario
        std::set<Clase*> Estudiante::listarClases(){
            return NULL;
        }
       bool Estudiante::tieneAsignatura(Asignatura *a){
            return false;
        }
        
//operaciones mismas de estudiante
        void Estudiante::eliminarAsignatura(Asignatura *a){

        }
        std::set<Asignatura*> Estudiante::getAsignaturas(){
            return NULL;
        }
        Asignatura *Estudiante::getAsignatura(string codigo){
            return NULL;
        }

        Estudiante::Estudiante(string nombre, string email, string contrasenia, string imagen, string ci):Usuario(nombre, email, imagen, contrasenia){
            this->ci = ci;
        }


