#include"clase.h"

DtFecha *Clase::getFechayhoracomienzo(){
    return this->fechayhoracomienzo;
}
void Clase::setFechayhoracomienzo(DtFecha *fecha){
    this->fechayhoracomienzo = fecha;
}
string Clase::getId(){
    return this->id;
}
void Clase::setId(string id){
    this->id = id;
}
bool Clase::getEnvivo(){
    return false;
}
void Clase::setEnvivo(bool b){
    this->envivo = b;
}
DtFecha Clase::getFechayhorafinal(){
    return this->fechayhorafinal;
}
void Clase::setFechayhorafinal(DtFecha *fecha){
    this->fechayhoracomienzo = fecha;
}
string Clase::getUrl(){
    return this->url;
}
void Clase::setUrl(string url){
    this->url = url;
}
string Clase::getNombre(){
    return this->nombre;
}
void Clase::setNombre(string nombre){
    this->nombre = nombre;
}

//metodos de las operaciones de la clase
Asignatura *Clase::getAsignatura(){
    return NULL;
}
bool Clase::getEnVivo(){
    return false;
}
void Clase::finalizar(){

}
bool Clase::tieneClaseEst(Estudiante *est){
    return false;
}
Claseestudiante *Clase::crearClaseEst(Estudiante *est, Clase *c){
    return NULL;
}
Claseestudiante *Clase::getClaseEstExistente(){
    return NULL;
}
std::set<Mensaje*> Clase::getMensajes(){
    return NULL;
}

Mensaje Clase::seleccionarMensaje(string idmensaje){
    return NULL;
}
void Clase::agregarPadre(Mensaje *m){

}

clase::Clase(string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc){
    this->nombre = nombre;
    this->fechayhoracomienzo = fecha;
    this->Asignatura = asignatura;
    this->Docente = doc;
}
