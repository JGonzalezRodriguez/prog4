#ifndef DTPREVIEW_H
#define DTPREVIEW_H

#include <string>
#include "dtfecha.h"
#include "dtdocente.h"
#include "dtestudiante.h"
#include "enums.h"
#include <set>

class DtPreview{
    private:
        DtFecha* fechayhoracomienzo;
        std::string id;
        std::string url; 
        DtDocente* docente;
        std::string nombre;
        modalidad mod;
        std::set<DtEstudiante*> estudiantes; // esto solo se usa si mod = monitoreo
    public:
        // si la clase es de modalidad teorico o practico conviene usar este contructor 
        DtPreview(modalidad mod, DtFecha* fechayhoracomienzo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        // si la clase es de modalidad monitoreo hay que usar este constructor para pasarle los estudiantes habilitados
        DtPreview(modalidad mod, std::set<DtEstudiante*> estudiantes,DtFecha* fechayhoracomienzo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        std::string getId();
        std::string getUrl();
        std::string getNombre();
        DtFecha* getFechaYHoraComienzo();
        DtDocente* getDocente();
        modalidad getMod();
        std::set<DtEstudiante*> getEstudiantes();
        //Notese que todas estas cosas estan definidas aca simplemente para no tener q definirlas tres veces en DtTeorico, DtPractico y DtMonitoreo. (se heredan)
};

std::ostream& operator<< (std::ostream& os, DtPreview &b);

#endif