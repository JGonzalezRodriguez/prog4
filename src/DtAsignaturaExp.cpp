#include "../include/DtAsignaturaExp.h"

DtAsignaturaExp::DtAsignaturaExp(bool tieneteo, bool tieneprac, bool tienemon){
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