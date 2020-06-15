#include "../include/ctrlasignatura.h"


CtrlAsignatura* CtrlAsignatura::instancia = NULL;

CtrlAsignatura* CtrlAsignatura::getInstancia() {
    if (instancia == NULL){
        instancia = new CtrlAsignatura;
    }
   return instancia; 
}

CtrlAsignatura::CtrlAsignatura() {};

std::map<std::string, DtAsignatura*> CtrlAsignatura::listarAsignaturas() {
    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> x = h->get();
    std::map<std::string, Asignatura*>::iterator it;
    std::map<std::string, DtAsignatura*> y;
    if (x.empty()) {
        std::cout << "\n No hay ninguna asignatura en el sistema. Por favor agregue asignaturas e intente nuevamente.\n";
        return y;
    }
    for ( it = x.begin(); it != x.end(); it++ )
    {
        y.insert(std::pair<std::string, DtAsignatura*>(it->first,it->second->getDt()));
    }
    return y;
}

void CtrlAsignatura::elegirAsignaturaAdmin(std::string codigo) {
    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    this->asig = h->find(codigo);
}

std::set<DtDocente*> CtrlAsignatura::listarDocentes() {
    Handlerusuarios* h = Handlerusuarios::getInstancia();
    std::set<Docente*> x = h->getDocentes();
    std::set<Docente*>::iterator it;
    std::set<DtDocente*> y;
    if (x.empty()) {
        std::cout << "\n No hay ningun docente en el sistema. Por favor agregue docentes e intente nuevamente.\n";
        return y;
    }
    for ( it = x.begin(); it != x.end(); it++ )
    {
        y.insert((*it)->getDt());
    }
    return y;
}

void CtrlAsignatura::elegirdocente(modalidad mod, std::string emaildocente) {
    this->mod = mod;
    Handlerusuarios* h = Handlerusuarios::getInstancia();
    this->doc = h->getDocente(emaildocente);
}

bool CtrlAsignatura::getConfi(){
    std::cout << "Desea asignar al docente %s a la asignatura %s con modalidad %s?" , this->doc->getNombre(), this->asig->getNombre(), std::to_string(this->mod);
    printf("\n 1. Si");
    printf("\n 2. No");
    int yn;
    scanf("%d", &yn);
    return (yn-1);
}

void CtrlAsignatura::confirmarAsignacionDocenteAsignatura(bool confi) {
    if (confi == true){
        Dicta* d = new Dicta(this->mod, this->doc, this->asig);
        this->doc->addAsignatura(d);
        this->asig->addDocente(d);
    }
}

void CtrlAsignatura::confirmarEliminacionAsignatura(bool conf) {

}