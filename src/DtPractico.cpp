#include "../include/DtPractico.h"

DtPractico::DtPractico(DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url,
    DtDocente* docente):DtClase(fechayhoracomienzo, fechayhorafinal, envivo, id, nombre, url, docente){
        //se ejecuta el constructor de DtClase
}

DtPractico::~DtPractico(){}