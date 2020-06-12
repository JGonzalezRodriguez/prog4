#include "ctrlclase.h"

Ctrlclase *Ctrlclase::instancia = NULL;

Ctrlclase::Ctrlclase(){

}
Ctrlclase *Ctrlclase::getInstancia(){
    if(instancia == NULL)
        instancia = new Ctrlclase();
    return instancia;
}

String Ctrlclase::getNombre(){
    return this->nombre;
}
void Ctrlclase::setNombre(string nombre){
    this->nombre = nombre;
}
DtFecha *Ctrlclase::getFecha(){
    return this->fecha;
}
void Ctrlclase::setFecha(DtFecha *fecha){
    this->fecha = fecha;
}
modalidad Ctrlclase::getMod(){
    return this->mod;
}
void Ctrlclase::setMod(modalidad mod){
    this->mod = mod;
}


void Ctrlclase::identificarse(string email, string contrasenia){

}
std::set<DtAsignatura*> Ctrlclase::listarAsignaturasDocente(){
    return NULL;
}
void Ctrlclase::inicioDeClase(string codigoasignatura, string nombre, DtFecha *fecha){

}
modalidad Ctrlclase::getModalidad(){
    return NULL;
}
std::set<DtEstudiante*> Ctrlclase::listarEstudiantesHabilatados(){
    return NULL;
}
void Ctrlclase::elegirEstudiante(string ci){

}
DtClase *Ctrlclase::mostrarDatos(){
    return NULL;
}
void Ctrlclase::confirmarInicioDeClase(bool conf){

}
std::set<DtClase*> Ctrlclase::listarClasesEnVivo(){
    return NULL;
}
void Ctrlclase::elegirClase(string id){

}
DtClase *Ctrlclase::mostrarClase(){
    return NULL;
}
void Ctrlclase::confirmarFinalizacionDeClase(bool conf){

}
void Ctrlclase::elegirAsignaturaDoc(string codigo){

}
std::set<DtClase*> Ctrlclase::listarClasesDocente(){
    return NULL;
}