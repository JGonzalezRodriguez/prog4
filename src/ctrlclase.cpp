#include "../include/ctrlclase.h"
#include <iostream>
#include "../include/handlerasignaturas.h"
#include "../include/dt/dtclase.h"
#include "../include/dt/dtpreview.h"
#include "../include/clase.h"
#include "../include/practico.h"
#include "../include/teorico.h"
#include "../include/monitoreo.h"
#include "../include/reloj.h"

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

void CtrlClase::setModalidad(modalidad mod){
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
void CtrlClase::inicioDeClase(std::string codigoasignatura, std::string nombre){
    this->nombre = nombre;
    Reloj* r = Reloj::getInstancia();
    this->fecha = r->getFecha();
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
DtPreview* CtrlClase::mostrarDatos(){
    mod = docente->getModalidad(asignatura);
    Reloj* r = Reloj::getInstancia();
    DtDocente* dtdoc = new DtDocente(docente->getInstituto(),docente->getNombre(),docente->getEmail(),docente->getImagen(),docente->getContrasenia());
    std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());

    if (mod == monitoreo) {
        std::set<DtEstudiante*> setdtest;
        for (std::set<Estudiante*>::iterator it=estudiantes.begin(); it!=estudiantes.end(); ++it) {
            Estudiante* est = *it;
            DtEstudiante* nuevodt = new DtEstudiante(est->getCi(),est->getNombre(),est->getEmail(),est->getImagen(),est->getContrasenia());
            setdtest.insert(nuevodt);
        }
        DtPreview* dtpreview = new DtPreview(mod, setdtest, r->getFecha(), std::to_string(Clase::getSeed()), nombre, url, dtdoc);
        // podria haber un problema en la string del url
        return dtpreview;
    } else {
        DtPreview* dtpreview = new DtPreview(mod, r->getFecha(), std::to_string(Clase::getSeed()), nombre, url, dtdoc);
        return dtpreview;
    }
    
    return NULL; // sin esto no compila, pero este caso nunca deberia suceder
}

void CtrlClase::confirmarInicioDeClase(bool conf){
    if (conf) {
        Reloj* r = Reloj::getInstancia();
        if (mod == practico) {
            Practico* c = new Practico(nombre, r->getFecha(), asignatura, docente);
            c->setEnVivo(true);
            std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());
            c->setUrl(url);
            int seed = Clase::getSeed();
            c->setId(std::to_string(seed));
            Clase::incSeed();
            docente->addClase(c);
            asignatura->addClase(c);
        } else if (mod == teorico) {
            Teorico* c = new Teorico(nombre, r->getFecha(), asignatura, docente);
            c->setEnVivo(true);
            std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());
            c->setUrl(url);
            int seed = Clase::getSeed();
            c->setId(std::to_string(seed));
            Clase::incSeed();
            docente->addClase(c);
            asignatura->addClase(c);
        } else if (mod == monitoreo) {
            Monitoreo* c = new Monitoreo(nombre, r->getFecha(), asignatura, docente);
            c->setEstudiantes(estudiantes);
            c->setEnVivo(true);
            std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());
            c->setUrl(url);
            int seed = Clase::getSeed();
            c->setId(std::to_string(seed));
            Clase::incSeed();
            docente->addClase(c);
            asignatura->addClase(c);
        }
    }
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