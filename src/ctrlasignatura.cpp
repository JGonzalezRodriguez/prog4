#include "../include/ctrlasignatura.h"
#include "../include/handlerasignaturas.h"

CtrlAsignatura *CtrlAsignatura::instancia = NULL;

CtrlAsignatura::CtrlAsignatura(){}

CtrlAsignatura* CtrlAsignatura::getInstancia() {
    if (instancia == NULL){
        instancia = new CtrlAsignatura;
    }
   return instancia; 
}

std::map<std::string, DtAsignatura*> CtrlAsignatura::listarAsignaturas() {
    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> x = h->get();
    std::map<std::string, Asignatura*>::iterator it;
    std::map<std::string, DtAsignatura*> y;
    if (x.empty()) {
        std::cout << "\n\033[1;31mNo hay ninguna asignatura en el sistema. Por favor agregue asignaturas e intente nuevamente.\033[0m\n";
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
        std::cout << "\n\033[1;31mNo hay ningun docente en el sistema. Por favor agregue docentes e intente nuevamente.\033[0m\n";
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