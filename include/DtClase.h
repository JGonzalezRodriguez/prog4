#ifndef DTCLASE_H
#define DTCLASE_H

#include <string>
#include "DtFecha.h"
#include "DtDocente.h"

class DtClase{
    private:
        DtFecha* fechayhoracomienzo;
        std::string id;
        bool envivo;
        DtFecha* fechayhorafinal;
        std::string url; //Es necesario? No hay reproduccion en diferido
        DtDocente* docente;
        std::string nombre;
    public: 
        DtClase(DtFecha fechayhoracomienzo, DtFecha fechayhorafinal, bool envivo, std::string id, std::string nombre, std::string url, DtDocente* docente);
        //El constructor nunca se usa solo ya que la clase no se instancia (es abstracta),
        //pero los constructores de cada uno de los hijos usaran este constructor (vease los cpp de DtTeorico, DtPractico, DtMonitoreo)
        virtual ~DtClase() = 0; //Funcion virtual pura; hace que la clase sea abstracta
        std::string getId();
        std::string getUrl();
        std::string getNombre();
        DtFecha* getFechaYHoraComienzo();
        DtFecha* getFechaYHoraFinal();
        DtDocente* getDocente();
        void setId(std::string id);
        void setUrl(std::string url);
        void setNombre(std::string nombre);
        void setFechaYHoraComienzo(DtFecha* fecha);
        void setFechaYHoraFinal(DtFecha* fecha);
        void setDocente(DtDocente* docente);
        //Notese que todas estas cosas estan definidas aca simplemente para no tener q definirlas tres veces en DtTeorico, DtPractico y DtMonitoreo. (se heredan)
};
#endif