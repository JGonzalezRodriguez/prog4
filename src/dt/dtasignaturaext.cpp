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

std::ostream& operator<< (std::ostream& os, DtAsignaturaExt &b) {
    os << "Nombre: " << b.getNombre() << std::endl << "Código: " << b.getCodigo() << std::endl << "Modalidades: \n";
    if (b.tieneTeo()) {
        os << "             Teorico\n";
    }
    if (b.tienePrac()) {
        os << "             Practico\n";
    }
    if (b.tieneMon()) {
        os << "             Monitoreo\n";
    }
    return os;
}