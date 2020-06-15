#include "../include/ctrlasignatura.h"


CtrlAsignatura* CtrlAsignatura::getInstancia() {
   return NULL; 
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

void CtrlAsignatura::identificarse(std::string email, std::string contrasenia){
    Handlerusuarios *u = Handlerusuarios::getInstancia();
    if(u->identificarse(email, contrasenia)){
        //si esta identificado el ctrl recuerda el email y la contrasenia
        this->email = email;
        this->contrasenia = contrasenia;
    }

}
std::set<DtAsignatura*> CtrlAsignatura::listarAsignaturasEstudiante(){
    //debe listar las asignaturas a las cuales el estudiante identificado no esta inscripto
    HandlerAsignaturas *a = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> asignaturas = a->get();
    
}
void CtrlAsignatura::elegirAsignaturaEst(std::string codigo){

}
void CtrlAsignatura::confirmarInscripcionAsignatura(bool confi){

}