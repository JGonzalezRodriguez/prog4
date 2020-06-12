#include "../include/DtAsignaturaExp.h"

DtAsignaturaExp::DtAsignaturaExp(std::string nombre, std::string codigo, bool tieneteo, bool tieneprac, bool tienemon) : DtAsignatura(nombre, codigo){
    this->tieneteo = tieneteo;
    this->tieneprac = tieneprac;
    this->tienemon = tienemon;
}

DtAsignaturaExp::~DtAsignaturaExp(){}

bool DtAsignaturaExp::tieneTeo(){
    return this->tieneteo;
}

bool DtAsignaturaExp::tienePrac(){
    return this->tieneprac;
}

bool DtAsignaturaExp::tieneMon(){
    return this->tienemon;
}