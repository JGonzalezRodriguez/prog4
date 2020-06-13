#include "../include/dt/dtasignaturaext.h"

DtAsignaturaExt::DtAsignaturaExt(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) : DtAsignatura(nombre, codigo){
    this->tieneteo = tieneteo;
    this->tieneprac = tieneprac;
    this->tienemon = tienemon;
}

DtAsignaturaExt::~DtAsignaturaExt(){}

bool DtAsignaturaExt::tieneTeo(){
    return this->tieneteo;
}

bool DtAsignaturaExt::tienePrac(){
    return this->tieneprac;
}

bool DtAsignaturaExt::tieneMon(){
    return this->tienemon;
}