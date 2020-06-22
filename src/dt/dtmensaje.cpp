#include <ostream>
#include "../include/dt/dtmensaje.h"

DtMensaje::DtMensaje(std::string texto, DtFecha* fechayhora, std::string id, std::string autor, std::set<DtMensaje*> respuestas){
    this->texto = texto;
    this->id = id;
    this->autor = autor;
    this->fechayhora = fechayhora;
    this->respuestas = respuestas;
}

DtMensaje::~DtMensaje(){}

std::string DtMensaje::getTexto(){
    return this->texto;
}

std::string DtMensaje::getId(){
    return this->id;
}

std::string DtMensaje::getAutor(){
    return this->autor;
}

DtFecha* DtMensaje::getFechaYHora(){
    return this->fechayhora;
}

std::set<DtMensaje*> DtMensaje::getRespuestas(){
    return this->respuestas;
}

std::ostream& operator<< (std::ostream& os, DtMensaje&b){
    DtFecha* f = b.getFechaYHora(); 
    os << "ID: " << b.getId() << std::endl << "Autor: " << b.getAutor() << std::endl << "Contenido: " << b.getTexto() << std::endl << "Fecha: " << f->getDia() << "/" << f->getMes() << "/" << f->getAnio() << " " << f->getHora() << ":" << f->getMin() << std::endl;
    return os;
}

void DtMensaje::recursivePrint(int iter){
    for (int i = 0; i <= iter; i++){
        printf("      ");
    }
    printf("ID: ");
    std::cout << this->getId();
    printf("\n");
    for (int j = 0; j <= iter; j++){
        printf("      ");
    }
    printf("Autor: ");
    std::cout << this->getAutor();
    printf("\n");
    for (int k = 0; k <= iter; k++){
        printf("      ");
    }
    printf("Contenido: ");
    std::cout << this->getTexto();
    printf("\n");
    for (int l = 0; l <= iter; l++){
        printf("      ");
    }
    printf("Fecha: ");
    DtFecha* f = this->getFechaYHora(); 
    std::cout << f->getDia();
    printf("/");
    std::cout << f->getMes();
    printf("/");
    std::cout << f->getAnio();
    printf(" ");
    std::cout << f->getHora();
    printf(":");
    std::cout << f->getMin();
    printf("\n------------------------------\n");
    std::set<DtMensaje*> msjs = this->respuestas;
    for (std::set<DtMensaje*>::iterator it=msjs.begin(); it!=msjs.end(); ++it){
        DtMensaje* msj = *it;
        msj->recursivePrint(iter+1);
    }
}
