#include "../include/clase.h"

int Clase::seed = 0;

int Clase::getSeed() { 
    return seed;
}

DtFecha *Clase::getFechayhoracomienzo(){
    return this->fechayhoracomienzo;
}
void Clase::setFechayhoracomienzo(DtFecha *fecha){
    this->fechayhoracomienzo = fecha;
}
std::string Clase::getId(){
    return this->id;
}
void Clase::setId(std::string id){
    this->id = id;
}
bool Clase::getEnVivo(){
    return this->envivo;
}
void Clase::setEnVivo(bool b){
    this->envivo = b;
}
DtFecha* Clase::getFechayhorafinal(){
    return this->fechayhorafinal;
}
void Clase::setFechayhorafinal(DtFecha *fecha){
    this->fechayhoracomienzo = fecha;
}
std::string Clase::getUrl(){
    return this->url;
}
void Clase::setUrl(std::string url){
    this->url = url;
}
std::string Clase::getNombre(){
    return this->nombre;
}
void Clase::setNombre(std::string nombre){
    this->nombre = nombre;
}

//metodos de las operaciones de la clase
Asignatura *Clase::getAsignatura(){
    return asig;
}

void Clase::finalizar(){

}
bool Clase::tieneClaseEst(Estudiante *est){
    return false;
}
ClaseEstudiante *Clase::crearClaseEst(Estudiante *est, Clase *c){
    return NULL;
}
ClaseEstudiante *Clase::getClaseEstExistente(){
    return NULL;
}
std::set<Mensaje*> Clase::getMensajes(){
    std::set<Mensaje*> x;
    return x;
}

Mensaje* Clase::seleccionarMensaje(std::string idmensaje){
    return NULL;
}
void Clase::agregarPadre(Mensaje *m){

}

Clase::Clase(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc){
    this->nombre = nombre;
    this->fechayhoracomienzo = fecha;
    this->asig = asignatura;
    this->doc = doc;
    this->envivo = true;
}
