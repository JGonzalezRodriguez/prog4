
#include "../include/ctrlreproduccion.h"

CtrlReproduccion* CtrlReproduccion::instancia = NULL;

CtrlReproduccion::CtrlReproduccion() {}

    CtrlReproduccion* CtrlReproduccion::getInstancia() {
        return NULL;
    }
    void CtrlReproduccion::identificarse(std::string email, std::string contrasenia){
        //todo
    }
    std::set<DtAsignatura*> CtrlReproduccion::listarAsignaturasEstudiante(){
        std::set<DtAsignatura*> trash;
        return trash;
    }
    void CtrlReproduccion::elegirAsignaturaEst(std::string codigo){
        //todo
    }
    std::set<DtClase*> CtrlReproduccion::listarClasesEstudiante(){
        std::set<DtClase*> trash;
        return trash;
    }
    void CtrlReproduccion::elegirClase(std::string id){
        //todo
    }
    DtClase* CtrlReproduccion::mostrarDatosClase(){
        return NULL;
    }
    // void confirmarReproduccionClaseEnDiferido(bool: confi);   #Esta no va si no hay reproduccion en diferido?
    std::set<DtMensaje*> CtrlReproduccion::ListarMensajes(){
        std::set<DtMensaje*> trash;
        return trash;
    }