#include "../include/clase.h"

int Clase::seed = 0;

int Clase::getSeed() { 
    return seed;
}

void Clase::incSeed() {
    seed = seed + 1;
}

void Clase::setDocente(Docente* doc){
    this->doc = doc;
}
Docente* Clase::getDocente(){
    return this->doc;
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

Docente* Clase::getDoc() {
    return this->doc;
}

//metodos de las operaciones de la clase
Asignatura *Clase::getAsignatura(){
    return asig;
}

void Clase::finalizar(){
    std::set<ClaseEstudiante*> colce = claseestudiantes;
    for (std::set<ClaseEstudiante*>::iterator it=colce.begin(); it!=colce.end(); ++it) {
        ClaseEstudiante* ce = *it;
        ce->finalizarVisualizacionesVivo();
    }
}
bool Clase::tieneClaseEst(Estudiante *est){
    std::set<ClaseEstudiante*>::iterator it = claseestudiantes.begin();
    for (it = claseestudiantes.begin(); it != claseestudiantes.end(); it++){
        if ((*it)->getEstudiante() == est){
            return true;
        }
    }
    return false;
}
ClaseEstudiante *Clase::crearClaseEst(Estudiante *est, Clase *c){
    ClaseEstudiante* ce = new ClaseEstudiante(c, est);
    this->claseestudiantes.insert(ce);
    return ce;
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
    this->fechayhorafinal = NULL;
    this->asig = asignatura;
    this->doc = doc;
    this->envivo = true;
}
Clase::~Clase(){
}
