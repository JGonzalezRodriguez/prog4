#ifndef DTCLASE_H
#define DTCLASE_H

#include <string>
#include "dtfecha.h"
#include "dtdocente.h"
#include "dtestudiante.h"
#include "enums.h"
#include <set>

class DtClase{
    private:
        DtFecha* fechayhoracomienzo;
        std::string id;
        bool envivo;
        DtFecha* fechayhorafinal;
        std::string url; //Es necesario? No hay reproduccion en diferido
        DtDocente* docente;
        std::string nombre;
        modalidad mod;
        std::set<DtEstudiante*> estudiantes; // esto solo se usa si mod = monitoreo
    public:
        // si la clase es de modalidad teorico o practico conviene usar este contructor 
        DtClase(modalidad mod, DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        // si la clase es de modalidad monitoreo hay que usar este constructor para pasarle los estudiantes habilitados
        DtClase(modalidad mod, std::set<DtEstudiante*> estudiantes,DtFecha* fechayhoracomienzo, DtFecha* fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        std::string getId();
        std::string getUrl();
        std::string getNombre();
        DtFecha* getFechaYHoraComienzo();
        DtFecha* getFechaYHoraFinal();
        DtDocente* getDocente();
        modalidad getMod();
        //Notese que todas estas cosas estan definidas aca simplemente para no tener q definirlas tres veces en DtTeorico, DtPractico y DtMonitoreo. (se heredan)
};

std::ostream& operator<< (std::ostream& os, DtClase &b);

#endif