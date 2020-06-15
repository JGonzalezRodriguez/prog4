#include "../include/ctrlclase.h"
#include <iostream>
#include "../include/handlerasignaturas.h"
#include "../include/dt/dtpractico.h"
#include "../include/dt/dtteorico.h"
#include "../include/dt/dtmonitoreo.h"

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
    return docente->getModalidad(asignatura);
}
std::set<DtEstudiante*> CtrlClase::listarEstudiantesHabilitados(){
    std::set<Estudiante*> colest = asignatura->getEstudiantes();
    std::set<DtEstudiante*> coldtest;
    for (std::set<Estudiante*>::iterator it=colest.begin(); it!=colest.end(); ++it) {
        Estudiante* est = *it;
        DtEstudiante* nuevodt = new DtEstudiante(est->getCi(),est->getNombre(),est->getEmail(),est->getImagen(),est->getContrasenia());
        coldtest.insert(nuevodt);
    }
    return coldtest;
}
void CtrlClase::elegirEstudiante(std::string ci){
    Estudiante* e = asignatura->getEstudiante(ci);
    if (e == NULL)
        throw std::invalid_argument("No hay un estudiante habilitado con esa CI");
    estudiantes.insert(e);
}
DtClase *CtrlClase::mostrarDatos(){
    Reloj* r = Reloj::getInstancia();
    DtDocente* dtdoc = new DtDocente(docente->getInstituto(),docente->getNombre(),docente->getEmail(),docente->getImagen(),docente->getContrasenia());
    if (mod == practico) { //DtPractico(DtFecha *fechayhoracomienzo, DtFecha *fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente *docente)
        DtPractico* dtclase = new DtPractico(r->getFecha(), NULL, true,  std::to_string(Clase::getSeed()), nombre, "https://fingclass.edu.uy/" + std::to_string(Clase::getSeed()), dtdoc);
         return dtclase;
    } else if (mod == teorico) {
        DtTeorico* dtclase = new DtTeorico(0 ,r->getFecha(), NULL, true,  std::to_string(Clase::getSeed()), nombre, "https://fingclass.edu.uy/" + std::to_string(Clase::getSeed()), dtdoc);
         return dtclase;
    } else if (mod == monitoreo) {
        std::set<DtEstudiante*> setdtest;
        for (std::set<Estudiante*>::iterator it=estudiantes.begin(); it!=estudiantes.end(); ++it) {
            Estudiante* est = *it;
            DtEstudiante* nuevodt = new DtEstudiante(est->getCi(),est->getNombre(),est->getEmail(),est->getImagen(),est->getContrasenia());
            setdtest.insert(nuevodt);
        }
        DtMonitoreo* dtclase = new DtMonitoreo(setdtest,r->getFecha(), NULL, true,  std::to_string(Clase::getSeed()), nombre, "https://fingclass.edu.uy/" + std::to_string(Clase::getSeed()), dtdoc);
         return dtclase;
    }
    return NULL; // sin esto no compila, pero este caso nunca deberia suceder
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