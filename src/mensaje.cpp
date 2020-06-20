#include "../include/mensaje.h"
#include "../include/usuario.h"
#include "../include/clase.h"

int Mensaje::seed = 1; //compile time B)

Mensaje::Mensaje(std::string texto, Clase* clase, Usuario* autor, bool esRaiz){
    this->id = std::to_string(this->seed);  // si no compila 
    this->seed++;                           // cambiar a Mensaje::seed
    this->clase = clase;
    this->texto = texto;
    this->autor = autor;
    this->isroot = esRaiz;
    Reloj* r = Reloj::getInstancia();
    DtFecha* f = new DtFecha(r->getFecha()); // f es una copia de dtfecha que hay en ese instante en el reloj
    this->fechayhoraenviado = f;         
}

Mensaje::~Mensaje(){}

Asignatura* Mensaje::getAsignatura(){
     return this->clase->getAsignatura();
}

Clase* Mensaje::getClase(){
    return this->clase;
}

DtFecha* Mensaje::getFechaYHoraEnviado(){
    return this->fechayhoraenviado;
}

std::string Mensaje::getTexto(){
    return this->texto;
}

std::string Mensaje::getId(){
    return this->id;
}

std::set<Mensaje*> Mensaje::getHijos(){
    return this->respondidopor;
}

void Mensaje::agregarHijo(Mensaje* m){
    this->respondidopor.insert(m);
}

bool Mensaje::esRaiz(){
    return this->isroot;
}

Mensaje *Mensaje::getPadre(){
    return this->padre;
}

void Mensaje::setPadre(Mensaje *m){
    this->padre = m;
}

Usuario *Mensaje::getAutor(){
    return this->autor;
}

DtMensaje* Mensaje::toDt(){
    DtFecha* fechayhora = new DtFecha(this->fechayhoraenviado);
    std::set<DtMensaje*> dthijos;
    for (std::set<Mensaje*>::iterator it=this->respondidopor.begin(); it!=this->respondidopor.end(); ++it){
        Mensaje* hijo = *it;
        dthijos.insert(hijo->toDt());
    }
    DtMensaje* dt = new DtMensaje(this->texto, fechayhora, this->id, this->autor->getNombre(), dthijos);
    return dt;
}
