#include "../include/ctrlclase.h"
#include <iostream>
#include "../include/handlerasignaturas.h"

CtrlClase *CtrlClase::instancia = NULL;

CtrlClase::CtrlClase(){
    this->fecha = NULL;
    this->asignatura = NULL;
    this->docente = NULL;
}

CtrlClase *CtrlClase::getInstancia(){
    if(instancia == NULL)
        instancia = new CtrlClase();
    return instancia;
}

std::string CtrlClase::getNombre(){
    return this->nombre;
}
void CtrlClase::setNombre(std::string nombre){
    this->nombre = nombre;
}
DtFecha *CtrlClase::getFecha(){
    return this->fecha;
}
void CtrlClase::setFecha(DtFecha *fecha){
    this->fecha = fecha;
}
modalidad CtrlClase::getMod(){
    return this->mod;
}
void CtrlClase::setMod(modalidad mod){
    this->mod = mod;
}


void CtrlClase::identificarse(std::string email, std::string contrasenia){
    Handlerusuarios* handu = Handlerusuarios::getInstancia();
    bool identi = handu->identificarse(email, contrasenia);
    if (!identi) 
        throw std::invalid_argument("Email o contraseña incorrectos");
    this->docente = handu->getDocente(email);
    if (this->docente == NULL)
        throw std::invalid_argument("Usted no es un docente");
}

std::set<DtAsignatura*> CtrlClase::listarAsignaturasDocente(){
    std::set<Asignatura*> colasig = docente->getAsignaturas();
    std::set<DtAsignatura*> coldtasig;
    for (std::set<Asignatura*>::iterator it=colasig.begin(); it!=colasig.end(); ++it) {
        DtAsignatura* nuevodt = new DtAsignatura((*it)->getNombre(), (*it)->getCodigo());
        coldtasig.insert(nuevodt);
    }
    return coldtasig;
}
void CtrlClase::inicioDeClase(std::string codigoasignatura, std::string nombre, DtFecha *fecha){
    this->nombre = nombre;
    this->fecha = fecha;
    std::set<Asignatura*> colasig = docente->getAsignaturas();
    bool encontro = false;
    for (std::set<Asignatura*>::iterator it=colasig.begin(); it!=colasig.end(); ++it) {
        Asignatura* a = *it;
        if (a->getCodigo() == codigoasignatura) {
            this->asignatura = a;
            encontro = true;
        }     
    }
    if (!encontro) 
        throw std::invalid_argument("El docente no tiene una asignatura con ese codigo");
}
modalidad CtrlClase::getModalidad(){
    return this->mod;
}
std::set<DtEstudiante*> CtrlClase::listarEstudiantesHabilitados(){
    std::set<DtEstudiante*> x;
    return x;
}
void CtrlClase::elegirEstudiante(std::string ci){

}
DtClase *CtrlClase::mostrarDatos(){
    return NULL;
}
void CtrlClase::confirmarInicioDeClase(bool conf){

}
std::set<DtClase*> CtrlClase::listarClasesEnVivo(){
    std::set<DtClase*> x;
    return x;
}
void CtrlClase::elegirClase(std::string id){

}
DtClase *CtrlClase::mostrarClase(){
    return NULL;
}
void CtrlClase::confirmarFinalizacionDeClase(bool conf){

}
void CtrlClase::elegirAsignaturaDoc(std::string codigo){

}
std::set<DtClase*> CtrlClase::listarClasesDocente(){
    std::set<DtClase*> x;
    return x;
}