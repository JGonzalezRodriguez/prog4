
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
            this->est = h->getEstudiante(email);
            std::cout << "\nBienvenide " << this->est->getNombre() << ".\n";
            return true;
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

            printf("TODO yes");
        } else {
            printf("Asistencia Cancelada");
        }
    }


    std::set<DtClase*> CtrlReproduccion::listarClasesEstudiante(){
        std::cout << "Estas son las clases en vivo para la asignatura " << this->a->getNombre() << ":";
        std::set<Clase*>::iterator it;
        std::set<DtClase*> x;
        this->colclase = a->getClases();
        for(it = this->colclase.begin(); it != colclase.end(); it++){
            if ((*it)->getEnVivo()) {
                modalidad m = (*it)->getDoc()->getModalidad((*it)->getAsignatura());
                DtDocente* doc = (*it)->getDoc()->getDt();
                DtClase* nueva = new DtClase(m,(*it)->getFechayhoracomienzo(),(*it)->getFechayhorafinal(),true,(*it)->getId(),(*it)->getNombre(),(*it)->getUrl(),doc);
                x.insert(nueva);
            }
            else {
            }
        }
        return x;
    }
    void CtrlReproduccion::elegirClase(std::string id){
        std::set<Clase*>::iterator it = this->a->getClases().begin();
        for(it = this->colclase.begin(); it != colclase.end(); it++){
            if ((*it)->getId() == id) {
                this->c = (*it);
            }
        }
    }
    DtClase* CtrlReproduccion::mostrarDatosClase(){
        DtClase* muestra = new DtClase(c->getDoc()->getModalidad(a),c->getFechayhoracomienzo(), c->getFechayhorafinal(), true, c->getId(), c->getNombre(), c->getUrl(), c->getDoc()->getDt());
        return muestra;
    }

    std::set<DtMensaje*> CtrlReproduccion::ListarMensajes(){
        std::set<DtMensaje*> trash;
        return trash;
    }
