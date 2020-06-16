#include "../include/ctrlasignatura.h"
#include "../include/handlerasignaturas.h"

CtrlAsignatura *CtrlAsignatura::instancia = NULL;

CtrlAsignatura::CtrlAsignatura(){}

CtrlAsignatura* CtrlAsignatura::getInstancia() {
    if(instancia == NULL)
        instancia = new CtrlAsignatura();
   return instancia; 
}


std::set<DtAsignatura*> CtrlAsignatura::listarAsignaturas() {
    std::set<DtAsignatura*> x;
    return x;
}

void CtrlAsignatura::elegirAsignaturaAdmin(std::string codigo) {

}

std::set<DtDocente*> CtrlAsignatura::listarDocentes() {
    std::set<DtDocente*> x;
    return x;
}

void CtrlAsignatura::elegirdocente(modalidad modalidad, std::string emaildocente) {

}

void CtrlAsignatura::confirmarAsignacionDocenteAsignatura(bool confi) {

}

void CtrlAsignatura::confirmarEliminacionAsignatura(bool conf) {

}

void CtrlAsignatura::altaAsignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon){
    this->asig = new Asignatura(nombre, codigo, tieneteo, tieneprac, tienemon);
}

DtAsignatura* CtrlAsignatura::mostrarDatosAsignatura(){
    // return this->asig.getDt(); 
    DtAsignatura* dummy = new DtAsignatura(this->asig->getNombre(), this->asig->getCodigo());
    return dummy;
    //TODO: borrar y descomentar
}

void CtrlAsignatura::confirmarAltaAsignatura(bool conf){
    if(conf){
        HandlerAsignaturas* handler = HandlerAsignaturas::getInstancia();
        handler->add(this->asig);
        printf("\nAsignatura dada de alta con exito.\n");
    }else{
        printf("\nCancelando. La asignatura no fue dada de alta.\n");
    }
}

bool CtrlAsignatura::getIdentificado(){
    return this->identificado;

}
bool CtrlAsignatura::getCodigovalido(){
    return this->codigovalido;
}



void CtrlAsignatura::identificarse(std::string email, std::string contrasenia){
    Handlerusuarios *u = Handlerusuarios::getInstancia();
    if(u->identificarse(email, contrasenia)){
        //si esta identificado el ctrl recuerda el email y la contrasenia
        this->email = email;
        this->contrasenia = contrasenia;
        this->identificado = true;
        //se podria guardar un puntero al estudiante pero se recuerdan el email y contrasenia
        //para seguir con los dss
    }else
    {
        this->identificado = false;
    }
    

}
std::set<DtAsignatura*> CtrlAsignatura::listarAsignaturasEstudiante(){
    //debe listar las asignaturas a las cuales el estudiante identificado no esta inscripto
    std::set<DtAsignatura*> res;
    
    HandlerAsignaturas *a = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> asignaturas = a->get();
    
    Handlerusuarios *u = Handlerusuarios::getInstancia();
    Estudiante *est = u->getEstudiante(this->email);
    
    std::map<std::string, Asignatura*>::iterator it;
    for(it = asignaturas.begin(); it != asignaturas.end(); ++it){
        std::set<Estudiante*> estudiantes = it->second->getEstudiantes();//estudiantes de la asignatura en cuestion
        std::set<Estudiante*>::iterator itest = estudiantes.find(est);
        if(itest == estudiantes.end()){//si no lo encontro quiere decir que no esta inscripto en esa asignatura
            std::string nombreasign = it->second->getNombre();
            std::string codigo = it->second->getCodigo();
            DtAsignatura *nuevo = new DtAsignatura(nombreasign, codigo);
            res.insert(nuevo);
        }
    }

    return res;
}
void CtrlAsignatura::elegirAsignaturaEst(std::string codigo){
    HandlerAsignaturas *a = HandlerAsignaturas::getInstancia();
    this->asig = a->find(codigo);
    //se recuerda la asignatura elegida
    this->codigovalido = true;
    if(this->asig == NULL)
        this->codigovalido = false;
    
}
void CtrlAsignatura::confirmarInscripcionAsignatura(bool confi){
    //si se confirma la inscripcion se deberia guardar la asignatura en la coleccion de asignaturas del estudiante identificado
    //y en la coleccion de estudiantes de la asignatura, guardar el estudiante identificado
    if(confi){
        Handlerusuarios *u = Handlerusuarios::getInstancia();
        Estudiante *est = u->getEstudiante(this->email);
        est->addAsignatura(this->asig);
        this->asig->addEstudiante(est);
    }
}