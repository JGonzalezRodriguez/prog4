#include "../include/ctrlasignatura.h"
#include "../include/handlerasignaturas.h"

CtrlAsignatura *CtrlAsignatura::instancia = NULL;

CtrlAsignatura::CtrlAsignatura(){
    
}

CtrlAsignatura *CtrlAsignatura::getInstancia() {
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
    DtAsignatura* dummy = new DtAsignatura("dummy", "dummy");
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