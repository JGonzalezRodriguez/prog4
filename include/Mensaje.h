#ifndef MENSAJE_H 
#define MENSAJE_H

#include <string>
#include <set>
#include "clase.h"
#include "asignatura.h"
#include "dt/dtfecha.h"
#include "reloj.h"

class Mensaje{
    private:
        static int seed;
        Clase* clase;
        DtFecha* fechayhoraenviado;
        std::string id;
        std::string texto;
        std::set<Mensaje*> respondidopor;
    public:
        Mensaje(std::string texto, Clase* clase);
        ~Mensaje();
        Asignatura* getAsignatura();
        Clase* getClase();
        DtFecha* getFechaYHoraEnviado();
        std::string getTexto();
        std::string getId();
        // std::set<Mensaje*> getHijos();
        void agregarHijo(Mensaje* m);
};

#endif
