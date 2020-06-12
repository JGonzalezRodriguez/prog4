#include "usuario.h"

    string Usuario::getNombre(){
        return this->nombre;
    }
    void Usuario::setNombre(string nombre){
        this->nombre = nombre;
    }
    string Usuario::getEmail(){
        return this->email;
    }
    void Usuario::setEmail(string email){
        this->email = email;
    }
    string Usuario::getImagen(){
        return this->imagen;
    }
    void Usuario::setImagen(string imagen){
        this->imagen = imagen;
    }
    
    string Usuario::getContrasenia(){
        return this->contrasenia;
    }
    void Usuario::setContrasenia(string contrasenia){
        this->contrasenia = contrasenia;
    }
    Usuario::Usuario(string nombre, string email, string imagen, string contrasenia){
        this->nombre = nombre;
        this->email = email;
        this->imagen = imagen;
        this->contrasenia = contrasenia;
    }

    Usuario::~Usuario(){}

        std::set<Notificacion*> Usuario::listarNotificaciones(){
            return NULL;
        }
        void Usuario::eliminarNotificaciones(){

        }
        void Usuario::eliminarNotificacionAsign(Asignatura *a){

        }
        void Usuario::elegirModo(subscripcion *subscripcion){

        }
        void Usuario::eliminarSubscripcion(){

        }
       
        Clase *Usuario::elegirClase(string id){
            return NULL;
        }
       
        void Usuario::notificarUsuario(Mensaje *m){

        }

   