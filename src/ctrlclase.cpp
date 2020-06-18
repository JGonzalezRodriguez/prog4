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
    DtFecha* f = new DtFecha(r->getFecha());
    DtDocente* dtdoc = new DtDocente(docente->getInstituto(),docente->getNombre(),docente->getEmail(),docente->getImagen(),docente->getContrasenia());
    std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());

    if (mod == monitoreo) {
        std::set<DtEstudiante*> setdtest;
        for (std::set<Estudiante*>::iterator it=estudiantes.begin(); it!=estudiantes.end(); ++it) {
            Estudiante* est = *it;
            DtEstudiante* nuevodt = new DtEstudiante(est->getCi(),est->getNombre(),est->getEmail(),est->getImagen(),est->getContrasenia());
            setdtest.insert(nuevodt);
        }
        DtPreview* dtpreview = new DtPreview(mod, setdtest, f, std::to_string(Clase::getSeed()), nombre, url, dtdoc);
        // podria haber un problema en la string del url
        return dtpreview;
    } else {
        DtPreview* dtpreview = new DtPreview(mod, f, std::to_string(Clase::getSeed()), nombre, url, dtdoc);
        return dtpreview;
    }
    
    return NULL; // sin esto no compila, pero este caso nunca deberia suceder
}

void CtrlClase::confirmarInicioDeClase(bool conf){
    if (conf) {
        Reloj* r = Reloj::getInstancia();
        DtFecha* f = new DtFecha(r->getFecha());
        if (mod == practico) {
            Practico* c = new Practico(nombre, f, asignatura, docente);
            c->setEnVivo(true);
            std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());
            c->setUrl(url);
            int seed = Clase::getSeed();
            c->setId(std::to_string(seed));
            Clase::incSeed();
            docente->addClase(c);
            asignatura->addClase(c);
        } else if (mod == teorico) {
            Teorico* c = new Teorico(nombre, f, asignatura, docente);
            c->setEnVivo(true);
            std::string url = "https://fingclass.edu.uy/" + asignatura->getNombre() + "/" + std::to_string(Clase::getSeed());
            c->setUrl(url);
            int seed = Clase::getSeed();
            c->setId(std::to_string(seed));
            Clase::incSeed();
            docente->addClase(c);
            asignatura->addClase(c);
        } else if (mod == monitoreo) {
            Monitoreo* c = new Monitoreo(nombre, f, asignatura, docente);
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
    this->estudiantes.clear();
}
std::set<DtPreview*> CtrlClase::listarClasesEnVivo(){
    std::set<Clase*> colclase = docente->getClasesEnVivo();
    std::set<DtPreview*> coldtpreview;
    for (std::set<Clase*>::iterator it=colclase.begin(); it!=colclase.end(); ++it) {
        Clase* clase = *it;

        modalidad mod = (clase->getDoc())->getModalidad(clase->getAsignatura());
        DtDocente* dtdoc = new DtDocente(docente->getInstituto(),docente->getNombre(),docente->getEmail(),docente->getImagen(),docente->getContrasenia());
        DtPreview* dtpreview = new DtPreview(mod, clase->getFechayhoracomienzo(), clase->getId(), clase->getNombre(), clase->getUrl(), dtdoc);
        coldtpreview.insert(dtpreview);
        
    }
    return coldtpreview;
}
void CtrlClase::elegirClase(std::string id){
    clase = docente->getClase(id);
}
DtPreview *CtrlClase::mostrarClase(){
    modalidad mod = (clase->getDoc())->getModalidad(clase->getAsignatura());
    DtDocente* dtdoc = new DtDocente(docente->getInstituto(),docente->getNombre(),docente->getEmail(),docente->getImagen(),docente->getContrasenia());
    DtPreview* dtpreview = new DtPreview(mod, clase->getFechayhoracomienzo(), clase->getId(), clase->getNombre(), clase->getUrl(), dtdoc);
    return dtpreview;
}
void CtrlClase::confirmarFinalizacionDeClase(bool conf){
    clase->finalizar();
    clase->setEnVivo(false);
    Reloj* r = Reloj::getInstancia();
    DtFecha* f = new DtFecha(r->getFecha());
    clase->setFechayhorafinal(f);
}
void CtrlClase::elegirAsignaturaDoc(std::string codigo){

}
std::set<DtClase*> CtrlClase::listarClasesDocente(){
    std::set<DtClase*> x;
    return x;
}

int CtrlClase::tiempoTranscurrido(DtFecha *fechacomienzo, DtFecha *fechafin){
    int cantminscomienzo, cantminsfin;
    int anio1, anio2, mes, dia, hora, min;
    anio1 = fechacomienzo->getAnio();
    anio2 = fechafin->getAnio();
    int tiempo;

    mes = fechacomienzo->getMes();
    dia = fechacomienzo->getDia();
    hora = fechacomienzo->getHora();
    min = fechacomienzo->getMin();
    cantminscomienzo = ((mes - 1)*30 + dia)*24*60 + hora*60 + min; //se pasa a minutos
    mes = fechafin->getMes();
    dia = fechafin->getDia();
    hora = fechafin->getHora();
    min = fechafin->getMin();
    cantminsfin = ((mes - 1)*30 + dia)*24*60 + hora*60 + min;
    
    if(anio1 == anio2){
        tiempo = cantminsfin - cantminscomienzo;
        return tiempo;
    }else{
        int restaanios = anio2 - anio1;
        cantminsfin = cantminsfin + restaanios*360*24*60;
        tiempo = cantminsfin - cantminscomienzo;
        return tiempo;

    }
    
}

std::set<DtTiempoAsignatura*> CtrlClase::tiempoDictadoClases(){
    HandlerAsignaturas *a = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> asignaturas = a->get();
    std::map<std::string, Asignatura*>::iterator it;
    std::set<DtTiempoAsignatura*> res;
    
    if(!asignaturas.empty()){
        for(it = asignaturas.begin(); it != asignaturas.end(); ++it){
            std::set<Clase*> clases = it->second->getClases();
            std::set<Clase*>::iterator itclase;
            int tiempotranscurrido = 0;
            for(itclase = clases.begin(); itclase != clases.end(); ++itclase){
                if(!(*itclase)->getEnVivo()){
                    tiempotranscurrido = tiempotranscurrido + tiempoTranscurrido((*itclase)->getFechayhoracomienzo(),(*itclase)->getFechayhorafinal());
                }
            }
            int horas, mins;
            horas = tiempotranscurrido/60;
            mins = tiempotranscurrido%60;
            DtTiempoAsignatura *nuevo = new DtTiempoAsignatura(it->second->getNombre(), horas, mins);
            res.insert(nuevo);

        }
    }else{
        throw std::invalid_argument("No hay asignaturas en el sistema");
    }
return res;

}