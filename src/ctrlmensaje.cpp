#include <stdexcept>
#include "../include/ctrlmensaje.h"
#include "../include/handlerusuarios.h"
#include "../include/dt/enums.h"
#include "../include/teorico.h"
#include "../include/practico.h"
#include "../include/monitoreo.h"

CtrlMensaje* CtrlMensaje::instancia = NULL;

CtrlMensaje::CtrlMensaje(){
    this->u = NULL;
    this->c = NULL;
    this->m = NULL;
}

CtrlMensaje::~CtrlMensaje(){}

CtrlMensaje* CtrlMensaje::getInstancia(){
    if(instancia == NULL){
        instancia = new CtrlMensaje();
    }
    return instancia;
}

Usuario* CtrlMensaje::getUsuario(){
    return this->u;
}

Clase* CtrlMensaje::getClase(){
    return this->c;
}

Mensaje* CtrlMensaje::getMensaje(){
    return this->m;
}

void CtrlMensaje::setUsuario(Usuario* u){
    this->u = u;
}

void CtrlMensaje::setClase(Clase* c){
    this->c = c;
}

void CtrlMensaje::setMensaje(Mensaje* m){
    this->m = m;
}

void CtrlMensaje::identificarse(std::string mail, std::string contrasenia){
    Handlerusuarios* handler = Handlerusuarios::getInstancia();
    if (handler->identificarse(mail, contrasenia)){
        this->u = handler->getUsuario(mail);
    }else{
        throw std::invalid_argument("\nDatos de identificación incorrectos");
    }
}

std::set<DtClase*> CtrlMensaje::listarClases(){
    Usuario* user = this->u;
    std::set<Clase*> clases = user->listarClases();
    std::set<DtClase*> dtclases;
    //iterando para crear un set de dtclases a partir de el set de clases
    for (std::set<Clase*>::iterator it=clases.begin(); it!=clases.end(); ++it){
        modalidad mod;
        //viendo la modalidad de la clase
        Clase* c = *it;
        if(dynamic_cast<Teorico*>(c) != NULL){
            mod = teorico;
        }else if(dynamic_cast<Practico*>(c) != NULL){
            mod = practico;
        }else{
            mod = monitoreo;
        }
        //copiando fechas
        DtFecha* fcomienzo = new DtFecha(c->getFechayhoracomienzo());
        DtFecha* ffinal = NULL;
        if (c->getFechayhorafinal() != NULL){
            ffinal = new DtFecha(c->getFechayhorafinal());
        }
        //creando dtdocente
        Docente* doc = c->getDocente();
        if (doc == NULL){//no deberia pasar nunca
            throw std::invalid_argument("\nERROR: se intento imprimir una clase que no tiene docente");
        }
        DtDocente* dtdoc = new DtDocente(doc->getInstituto(), doc->getNombre(), doc->getEmail(), doc->getImagen(), doc->getContrasenia());
        //creando dtclase
        DtClase* dtclase = new DtClase(mod, fcomienzo, ffinal, c->getEnVivo(), c->getId(), c->getNombre(), c->getUrl(), dtdoc);
        //agregando al set
        dtclases.insert(dtclase);
    }
    return dtclases;
}

void CtrlMensaje::elegirClase(std::string id){
    Usuario* user = this->u;
    this->c = user->elegirClase(id);
}

std::set<DtMensaje*> CtrlMensaje::listarMensajes(){
    //solo agarra los mensajes raiz para que luego recursivePrint no repita mensaje
    std::set<Mensaje*> msjs = this->c->getMensajes();
    std::set<DtMensaje*> dtmsjs;
    for (std::set<Mensaje*>::iterator it=msjs.begin(); it!=msjs.end(); ++it){
        Mensaje* msj = *it;
        if (msj->esRaiz()){
            dtmsjs.insert(msj->toDt());
        }
    }
    return dtmsjs;
}

void CtrlMensaje::seleccionarMensaje(std::string idMensaje){
    std::set<Mensaje*> msjs = this->c->getMensajes();
    for (std::set<Mensaje*>::iterator it=msjs.begin(); it!=msjs.end(); ++it){
        Mensaje* msj = *it;
        if(msj->getId() == idMensaje){
            this->m = msj;
        }
    }
    if(this->m == NULL){
        throw std::invalid_argument("\nEl ID ingresado no corresponde a ninguno de los mensajes de esta clase");
    }

}

void CtrlMensaje::textoEnviar(std::string texto){
    this->texto = texto;
}

void CtrlMensaje::confirmarEnvioMensaje(bool conf){
    if (conf){
        bool esRaiz = true;
        if(this->m != NULL){
            esRaiz = false;
        }
        Mensaje* msj = new Mensaje(this->texto, this->c, this->u, esRaiz);
        if(!esRaiz){
            this->m->agregarHijo(msj);
        }
        this->c->agregarPadre(msj); //mal nombre. agregarMensaje seria mejor
    }
}