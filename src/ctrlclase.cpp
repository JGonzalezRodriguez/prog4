#include "../include/ctrlclase.h"

CtrlClase *CtrlClase::instancia = NULL;

CtrlClase::CtrlClase(){
    this->fecha = NULL;
    this->asignatura = NULL;
    this->docente = NULL;
}

CtrlClase *CtrlClase::getInstancia(){
    if(instancia == NULL)
        instancia = new CtrlClase();
    return instancia;
}

std::string CtrlClase::getNombre(){
    return this->nombre;
}
void CtrlClase::setNombre(std::string nombre){
    this->nombre = nombre;
}
DtFecha *CtrlClase::getFecha(){
    return this->fecha;
}
void CtrlClase::setFecha(DtFecha *fecha){
    this->fecha = fecha;
}
modalidad CtrlClase::getMod(){
    return this->mod;
}
void CtrlClase::setMod(modalidad mod){
    this->mod = mod;
}


void CtrlClase::identificarse(std::string email, std::string contrasenia){

}
std::set<DtAsignatura*> CtrlClase::listarAsignaturasDocente(){
    std::set<DtAsignatura*> x;
    return x;
}
void CtrlClase::inicioDeClase(std::string codigoasignatura, std::string nombre, DtFecha *fecha){

}
modalidad CtrlClase::getModalidad(){
    return this->mod;
}
std::set<DtEstudiante*> CtrlClase::listarEstudiantesHabilatados(){
    std::set<DtEstudiante*> x;
    return x;
}
void CtrlClase::elegirEstudiante(std::string ci){

}
DtClase *CtrlClase::mostrarDatos(){
    return NULL;
}
void CtrlClase::confirmarInicioDeClase(bool conf){

}
std::set<DtClase*> CtrlClase::listarClasesEnVivo(){
    std::set<DtClase*> x;
    return x;
}
void CtrlClase::elegirClase(std::string id){

}
DtClase *CtrlClase::mostrarClase(){
    return NULL;
}
void CtrlClase::confirmarFinalizacionDeClase(bool conf){

}
void CtrlClase::elegirAsignaturaDoc(std::string codigo){

}
std::set<DtClase*> CtrlClase::listarClasesDocente(){
    std::set<DtClase*> x;
    return x;
}