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
        DtFecha* comienzo = new DtFecha(c->getFechayhoracomienzo());
        DtFecha* final = new DtFecha(c->getFechayhorafinal());
        //creando dtdocente
        Docente* doc = c->getDocente();
        DtDocente* dtdoc = new DtDocente(doc->getInstituto(), doc->getNombre(), doc->getEmail(), doc->getImagen(), doc->getContrasenia());
        //creando dtclase
        DtClase* dtclase = new DtClase(mod, comienzo, final, c->getEnVivo(), c->getId(), c->getNombre(), c->getUrl(), dtdoc);
        //agregando al set
        dtclases.insert(dtclase);
    }

    return dtclases;
}

void CtrlMensaje::elegirClase(std::string id){
    //TODO
}

std::set<DtMensaje*> CtrlMensaje::listarMensajes(){
    //TODO
    std::set<DtMensaje*> x;
    return x;
}

void CtrlMensaje::seleccionarMensaje(std::string idMensaje){
    //TODO
}

void CtrlMensaje::textoEnviar(std::string texto){
    //TODO
}

void CtrlMensaje::confirmarEnvioMensaje(bool conf){
    //TODO
}