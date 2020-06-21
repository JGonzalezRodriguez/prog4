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

std::set<DtAsignatura*> CtrlAsignatura::listarAsignaturas() {
    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    std::map<std::string, Asignatura*> x = h->get();
    std::map<std::string, Asignatura*>::iterator it;
    std::set<DtAsignatura*> y;
    if (x.empty()) {
        std::cout << "\n\033[1;31mNo hay ninguna asignatura en el sistema. Por favor agregue asignaturas e intente nuevamente.\033[0m\n";
        return y;
    }
    for ( it = x.begin(); it != x.end(); it++ )
    {
        y.insert(it->second->getDt());


    }
    return y;
}

void CtrlAsignatura::elegirAsignaturaAdmin(std::string codigo) {
    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    this->asig = h->find(codigo);
    if (this->asig == NULL) throw std::invalid_argument("codigo invalido");
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
        std::set<Asignatura*> colec = (*it)->getAsignaturas();
        std::set<Asignatura*>::iterator itasign = colec.find(this->asig);
        if(itasign == colec.end()){
            y.insert((*it)->getDt());//crea el DtType y lo retorna;
        }
    }
    return y;
}

bool CtrlAsignatura::tieneAsignaturaMod(modalidad mod){
    bool tienemod = false;
    if(mod == teorico && this->asig->tieneTeo())
        tienemod = true;
    
    else{ if(mod == practico && this->asig->tienePrac())
            tienemod = true;
    
            else{if(mod == monitoreo && this->asig->tieneMon())
                tienemod = true;
            }
    }

    return tienemod;
}

void CtrlAsignatura::imprimirModalidad(){
    printf("\n Modalidades de la Asignatura");
    if(this->asig->tieneTeo())
        printf("\n* Teórico");
    
    if(this->asig->tienePrac())
        printf("\n* Práctico");
    
    if(this->asig->tieneMon())
        printf("\n* Monitoreo");
    printf("\n");

}

void CtrlAsignatura::elegirdocente(modalidad mod, std::string emaildocente) {
    this->mod = mod;
    Handlerusuarios* h = Handlerusuarios::getInstancia();
    this->doc = h->getDocente(emaildocente);
}

bool CtrlAsignatura::getConfi(){
    std::cout << "\nDesea asignar al docente "<<this->doc->getNombre()<< " a la asignatura " << this->asig->getNombre() << " con la modalidad seleccionada?" << std::endl;
    printf("\n 1. Si");
    printf("\n 2. No");
    printf("\n");
    bool confi = false;
    char inst;
    scanf("%s", &inst);
    if(inst == '1'){
        confi = true;
    }
    return confi;

}

void CtrlAsignatura::confirmarAsignacionDocenteAsignatura(bool confi) {
    if (confi == true){
        Dicta* d = new Dicta(this->mod, this->doc, this->asig);
        this->doc->addAsignatura(d);
        this->asig->addDocente(d);
    }
}

void CtrlAsignatura::confirmarEliminacionAsignatura(bool conf) {
    if (conf == false) {
        printf("Cancelado.");
        return;
    }

    HandlerAsignaturas* h = HandlerAsignaturas::getInstancia();
    h->remove(asig);

    std::set<Estudiante*> x =asig->getEstudiantes();
    std::set<Estudiante*>::iterator it;
    for(it = x.begin(); it != x.end(); it++) {
        (*it)->eliminarNotificacionAsign(asig);
        (*it)->eliminarAsignatura(asig);
        printf("loop 1\n");
    }

    std::set<Dicta*> y = asig->getDictas();
    std::set<Dicta*>::iterator it2;
    for(it2 = y.begin(); it2 != y.end(); it2++) {
        (*it2)->getDocente()->eliminarNotificacionAsign(asig);
        (*it2)->getDocente()->deslinkear(*it2);
        printf("loop 2\n");
        delete (*it2); //Delete Dicta
    }

    std::set<Clase*> z = asig->getClases();
    std::set<Clase*>::iterator it3;
    for(it3=z.begin(); it3 != z.end(); it3++){
        std::set<ClaseEstudiante*> ces = (*it3)->getClaseEstudiantes();
        std::set<ClaseEstudiante*>::iterator it4;
        for(it4=ces.begin(); it4 != ces.end(); it4++){
            (*it4)->getEstudiante()->deslinkear(*it4);
            (*it4)->getClase()->deslinkear(*it4);
            printf("loop 3.1\n");
            delete (*it4); // Delete ClaseEstudiante
        }
        std::set<Mensaje*> colMensajes = (*it3)->getMensajes();
        std::set<Mensaje*>::iterator it5;
        for(it5=colMensajes.begin(); it5 != colMensajes.end(); it5++){
            printf("loop 3.2\n");
            delete (*it5); // Delete Mensaje
        }
        printf("loop 3\n");
        delete *it3; // Delete la Clase
    }  

}

void CtrlAsignatura::altaAsignatura(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon){
    this->asig = new Asignatura(nombre, codigo, tieneteo, tieneprac, tienemon);
}

DtAsignaturaExt* CtrlAsignatura::mostrarDatosAsignatura(){
    // return this->asig.getDt(); 
    DtAsignaturaExt* dummy = new DtAsignaturaExt(this->asig->getNombre(), this->asig->getCodigo(), asig->tieneMon(), asig->tienePrac(), asig->tieneTeo());
    return dummy;
    //TODO: borrar y descomentar
}

void CtrlAsignatura::confirmarAltaAsignatura(bool conf){
    if(conf){
        HandlerAsignaturas* handler = HandlerAsignaturas::getInstancia();
        handler->add(this->asig);
        // printf("\nAsignatura dada de alta con exito.\n"); // No deberia haber prints en la capa lógica!!!!!!!!!!
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
    if(u->identificarse(email, contrasenia) && u->getDocente(email) == NULL){
        
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