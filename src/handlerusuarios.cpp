#include "../include/handlerusuarios.h"

Handlerusuarios *Handlerusuarios::instancia = NULL;

Handlerusuarios::Handlerusuarios(){

}

Handlerusuarios *Handlerusuarios::getInstancia(){
    if(instancia == NULL)
        instancia = new Handlerusuarios();
    return instancia;
}

void Handlerusuarios::add(Usuario *u){

}
std::set<Docente*> Handlerusuarios::getDocentes(){
    return NULL;
}
Docente *Handlerusuarios::getDocente(std::string email){
    return NULL;
}
bool Handlerusuarios::identificarse(std::string email, std::string contrasenia){
    return false;
}
Estudiante *Handlerusuarios::getEstudiante(std::string email){
    return NULL;
}
Usuario *Handlerusuarios::getUsuario(std::string email){
    return NULL;
}
void Handlerusuarios::notificar(Asignatura *a, Mensaje *m){

}
void Handlerusuarios::addSubscripto(Usuario *u){

}
void Handlerusuarios::removerSubscripto(Usuario *u){

}