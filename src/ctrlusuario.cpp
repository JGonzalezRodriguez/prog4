#include "ctrlusuario.h"

Ctrlusuario *Ctrlusuario::instancia = NULL;

Ctrlusuario::Ctrlusuario(){

}

Ctrlusuario *Ctrlusuario::getInstancia(){
    if(instancia == NULL)
        instancia = new Ctrlusuario();
    return instancia;
}

string Ctrlusuario::getNombre(){
        return this->nombre;
    }
void Ctrlusuario::setNombre(string nombre){
        this->nombre = nombre;
    }
string Ctrlusuario::getEmail(){
        return this->email;
    }
void Ctrlusuario::setEmail(string email){
        this->email = email;
    }
string Ctrlusuario::getImagen(){
        return this->imagen;
    }
void Ctrlusuario::setImagen(string imagen){
        this->imagen = imagen;
    }
    
string Ctrlusuario::getContrasenia(){
        return this->contrasenia;
    }
void Ctrlusuario::setContrasenia(string contrasenia){
        this->contrasenia = contrasenia;
    }

string Ctrlusuario::getCi(){
    return this->ci;
}
void Ctrlusuario::setCi(string ci){
    this->ci = ci;
}
instituto Ctrlusuario::getInstituto(){
    return NULL;
}
void Ctrlusuario::setInstituto(instituto instituto){
    this->instituto = instituto;
}

bool Ctrlusuario::getEsdocente(){
    return false;
}
void Ctrlusuario::setEsdocente(bool b){
    this->esdocente = b;
}

void Ctrlusuario::altaDocente(string nombre, string email, string contrasenia, string imagen, instituto instituto){

}
void Ctrlusuario::altaEstudiante(string nombre, string email, string contrasenia, string imagen, string ci){

}
void Ctrlusuario::confirmarAltaUsuario(bool conf){
    
}