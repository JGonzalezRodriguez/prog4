
#include "../include/ctrlreproduccion.h"

CtrlReproduccion* CtrlReproduccion::instancia = NULL;

CtrlReproduccion::CtrlReproduccion() {}

    CtrlReproduccion* CtrlReproduccion::getInstancia() {
        if (instancia == NULL){
            instancia = new CtrlReproduccion();
        }  
        return instancia;
    }


    bool CtrlReproduccion::identificarse(std::string email, std::string contrasenia){
        Handlerusuarios* h = Handlerusuarios::getInstancia();
        if (h->identificarse(email, contrasenia)){
            if (h->getEstudiante(email) != NULL) {
            this->est = h->getEstudiante(email);
            std::cout << "\nBienvenide " << this->est->getNombre() << ".\n";
            return true;
            } else {
                throw std::invalid_argument("Usted no es un estudiante.");
            }
        } else {
            printf("El usuario y/o contrasenia son incorrectos.");
            return false;
        }
    }

    std::set<DtAsignatura*> CtrlReproduccion::listarAsignaturasEstudiante(){
        std::set<Asignatura*>::iterator it;
        std::set<Asignatura*> lista = this->est->getAsignaturas();
        std::set<DtAsignatura*> res;
        for(it = lista.begin(); it != lista.end(); it++){
            res.insert((*it)->getDt());
        }
        return res;
    }

    void CtrlReproduccion::elegirAsignaturaEst(std::string codigo){
        this->a = this->est->getAsignatura(codigo);
    }

    void CtrlReproduccion::confirmarAsistenciaClaseEnVivo(bool confi){
        if (confi) {
            ClaseEstudiante* ce;
            if (!c->tieneClaseEst(est)){
                ce = c->crearClaseEst(est, c);
                if (ce->getavivo()->getEstaMirando() && c->tieneClaseEst(est)){
                    printf("Asistiendo a la clase");
                }
            }
            if (c->tieneClaseEst(est)) {
                ce = c->getClaseEstExistente(est);
                if (ce == NULL) {
                    throw ("Error de backend.");
                }
                ce->asistirVivo();
                if (c->getClaseEstExistente(est)->getavivo()) {
                    printf("Asistiendo a la clase");
                }
            };
        } else {
            printf("Asistencia Cancelada");
        }
    }


    std::set<DtClase*> CtrlReproduccion::listarClasesEstudiante(){
        std::set<Clase*>::iterator it;
        std::set<DtClase*> x;
        this->colclase = a->getClases();
        for(it = this->colclase.begin(); it != colclase.end(); it++){
            if (!(*it)->getEnVivo()) {
                continue;
            }
            if ((*it)->tieneClaseEst(est)) {
                if ((*it)->getClaseEstExistente(est)->getavivo()->getEstaMirando()){
                    continue;
                }
            }
            modalidad m = (*it)->getDocente()->getModalidad((*it)->getAsignatura());
            DtDocente* doc = (*it)->getDocente()->getDt();
            DtClase* nueva = new DtClase(m,(*it)->getFechayhoracomienzo(),(*it)->getFechayhorafinal(),true,(*it)->getId(),(*it)->getNombre(),(*it)->getUrl(),doc);
            x.insert(nueva);
        }
        if (!x.empty()) {
            std::cout << "Estas son las clases en vivo para la asignatura " << this->a->getNombre() << ":";
        } else {
            printf("\nNo hay clases disponibles"); 
            }
        return x;
    }
    void CtrlReproduccion::elegirClase(std::string id){
        std::set<Clase*>::iterator it = this->est->listarClases().begin();
        bool encuentra = false;
        for(it = this->colclase.begin(); it != colclase.end(); it++){
            if ((*it)->getId() == id) {
                this->c = (*it);
                encuentra = true;
            }
        }
        if (!encuentra) { throw std::invalid_argument("Id no Valido"); }
    }
    DtClase* CtrlReproduccion::mostrarDatosClase(){
        DtClase* muestra = new DtClase(c->getDocente()->getModalidad(a),c->getFechayhoracomienzo(), c->getFechayhorafinal(), true, c->getId(), c->getNombre(), c->getUrl(), c->getDocente()->getDt());
        return muestra;
    }

    std::set<DtMensaje*> CtrlReproduccion::ListarMensajes(){
        std::set<DtMensaje*> trash;
        return trash;
    }

    bool CtrlReproduccion::estaAsistiendo(){
        return this->est->estaAsistiendo();
    }

    std::set<DtClase*> CtrlReproduccion::listarClasesEstudianteVivo(){
        std::set<Clase*>::iterator it;
        std::set<DtClase*> x;
        this->colclase = est->listarClasesVivo();
        for(it = this->colclase.begin(); it != colclase.end(); it++){
                modalidad m = (*it)->getDocente()->getModalidad((*it)->getAsignatura());
                DtDocente* doc = (*it)->getDocente()->getDt();
                DtClase* nueva = new DtClase(m,(*it)->getFechayhoracomienzo(),(*it)->getFechayhorafinal(),true,(*it)->getId(),(*it)->getNombre(),(*it)->getUrl(),doc);
                x.insert(nueva);
        }

        if (!x.empty()) {
            std::cout << "\nEstas son las clases a las que usted esta asistiendo " << this->a->getNombre() << ":";
        } else {
            printf("\nNo esta asistiendo a ninguna clase"); 
            }
        return x;
    }

    void CtrlReproduccion::confirmarFinalizacionAsistencia(bool confi) {
        if (confi) {
            if (!c->tieneClaseEst(est)){
                throw "No esta asistiendo a esta clase.";
            };
            c->getClaseEstExistente(est)->finalizarVisualizacionesVivo();
            printf("Asistencia terminada");
        } else {
            printf("Cancelado.");
        }
    }

