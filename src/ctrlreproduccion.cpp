
#include "../include/ctrlreproduccion.h"
#include <set>

    IReproduccion CtrlReproduccion::getInstancia() {
        return instancia;
    }
    void CtrlReproduccion::identificarse(std::string email, std::string contrasenia){
        //todo
    }
    std::set<DtAsignatura> CtrlReproduccion::listarAsignaturasEstudiante(){
        //todo
        return trash = new set<DtAsignatura>;
    }
    void CtrlReproduccion::elegirAsignaturaEst(std::string codigo){
        //todo
    }
    std::set<DtClase> CtrlReproduccion::listarClasesEstudiante(){
        //todo
        return trash = new set<DtClase>;
    }
    void CtrlReproduccion::elegirClase(std::string id){
        //todo
    }
    DtClase CtrlReproduccion::mostrarDatosClase(){
        return trash = new DtClase;
    }
    // void confirmarReproduccionClaseEnDiferido(bool: confi);   #Esta no va si no hay reproduccion en diferido?
    std::set<DtMensaje> CtrlReproduccion::ListarMensajes(){
        //todo
        return trash = new set<DtMensaje>;
    }