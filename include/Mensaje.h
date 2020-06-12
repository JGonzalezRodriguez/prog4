#ifndef MENSAJE_H 
#define MENSAJE_H

#include <string>
#include <set>
#include "Clase.h"
#include "Asignatura.h"
#include "DtFecha.h"

class Mensaje{
    private:
        Clase* clase;
        DtFecha fechayhoraenviado;
        std::string id;
        std::string texto;
        std::set<Mensaje*> respondidopor;
    public:
        Mensaje(std::string texto, Clase* clase);
        ~Mensaje();
        Asignatura* getAsignatura();
        Clase* getClase();
        DtFecha getFechaYHoraEnviado();
        std::string getTexto();
        std::string getId();
        std::set<Mensaje*> getHijos();
        void agergarHijo(Mensaje* m);
};

#endif
