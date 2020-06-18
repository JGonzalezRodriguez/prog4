#include <stdexcept>
#include "../include/estudiante.h"

std::string Estudiante::getCi(){
    return this->ci;
}
void Estudiante::setCi(std::string ci){
    this->ci = ci;
}

//operaciones que hereda de usuario
        std::set<Clase*> Estudiante::listarClases(){
            std::set<Clase*> clases;
            for (std::set<ClaseEstudiante*>::iterator it=this->claseestudiantes.begin(); it!=this->claseestudiantes.end(); ++it){
                ClaseEstudiante* ce = *it;
                clases.insert(ce->getClase());
            }
            return clases;
        }
       bool Estudiante::tieneAsignatura(Asignatura *a){
            return false;
        }
       Clase* Estudiante::elegirClase(std::string id){
            std::set<ClaseEstudiante*> ces = this->claseestudiantes;
            for (std::set<ClaseEstudiante*>::iterator it=ces.begin(); it!=ces.end(); ++it){
                ClaseEstudiante* ce = *it;
                Clase* c = ce->getClase();
                if (c->getId() == id){
                    return c;
                }
            }
            //si el estudiante no esta en ninguna clase con ese id
            throw std::invalid_argument("\nEl usuario no tiene está en ninguna clase con ese ID");
       }
        
//operaciones mismas de estudiante
        void Estudiante::eliminarAsignatura(Asignatura *a){

        }
        std::set<Asignatura*> Estudiante::getAsignaturas(){
            return this->asignaturas;
        }
        Asignatura *Estudiante::getAsignatura(std::string codigo){
            return NULL;
        }

        Estudiante::Estudiante(std::string nombre, std::string email, std::string contrasenia, std::string imagen, std::string ci):Usuario(nombre, email, imagen, contrasenia){
            this->ci = ci;
        }

        void Estudiante::addAsignatura(Asignatura *a){
            this->asignaturas.insert(a);
        }
