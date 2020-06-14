#include "../include/ctrlusuario.h"

CtrlUsuario *CtrlUsuario::instancia = NULL;

CtrlUsuario::CtrlUsuario(){

}

CtrlUsuario *CtrlUsuario::getInstancia(){
    if(instancia == NULL)
        instancia = new CtrlUsuario();
    return instancia;
}

std::string CtrlUsuario::getNombre(){
        return this->nombre;
    }
void CtrlUsuario::setNombre(std::string nombre){
        this->nombre = nombre;
    }
std::string CtrlUsuario::getEmail(){
        return this->email;
    }
void CtrlUsuario::setEmail(std::string email){
        this->email = email;
    }
std::string CtrlUsuario::getImagen(){
        return this->imagen;
    }
void CtrlUsuario::setImagen(std::string imagen){
        this->imagen = imagen;
    }
    
std::string CtrlUsuario::getContrasenia(){
        return this->contrasenia;
    }
void CtrlUsuario::setContrasenia(std::string contrasenia){
        this->contrasenia = contrasenia;
    }

std::string CtrlUsuario::getCi(){
    return this->ci;
}
void CtrlUsuario::setCi(std::string ci){
    this->ci = ci;
}
instituto CtrlUsuario::getInstituto(){
    return instituto(1);
}
void CtrlUsuario::setInstituto(instituto instituto){
    this->inst = instituto;
}

bool CtrlUsuario::getEsdocente(){
    return false;
}
void CtrlUsuario::setEsdocente(bool b){
    this->esdocente = b;
}

void CtrlUsuario::altaDocente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto instituto){

}
void CtrlUsuario::altaEstudiante(std::string nombre, std::string email, std::string contrasenia, std::string imagen, std::string ci){

}
void CtrlUsuario::confirmarAltaUsuario(bool conf){
    
}