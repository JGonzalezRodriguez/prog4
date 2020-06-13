#include "../include/usuario.h"

    std::string Usuario::getNombre(){
        return this->nombre;
    }
    void Usuario::setNombre(std::string nombre){
        this->nombre = nombre;
    }
    std::string Usuario::getEmail(){
        return this->email;
    }
    void Usuario::setEmail(std::string email){
        this->email = email;
    }
    std::string Usuario::getImagen(){
        return this->imagen;
    }
    void Usuario::setImagen(std::string imagen){
        this->imagen = imagen;
    }
    
    std::string Usuario::getContrasenia(){
        return this->contrasenia;
    }
    void Usuario::setContrasenia(std::string contrasenia){
        this->contrasenia = contrasenia;
    }
    Usuario::Usuario(std::string nombre, std::string email, std::string imagen, std::string contrasenia){
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
       
        Clase *Usuario::elegirClase(std::string id){
            return NULL;
        }
       
        void Usuario::notificarUsuario(Mensaje *m){

        }

   