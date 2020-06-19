#ifndef MENSAJE_H 
#define MENSAJE_H

#include <string>
#include <set>
#include "clase.h"
#include "asignatura.h"
#include "dt/dtfecha.h"
#include "dt/dtmensaje.h"
#include "reloj.h"

class Clase;
class Asignatura;
class Usuario;

class Mensaje{
    private:
        static int seed;
        Clase* clase;
        DtFecha* fechayhoraenviado;
        std::string id;
        std::string texto;
        Usuario* autor;
        bool isroot;
        std::set<Mensaje*> respondidopor;
    public:
        Mensaje(std::string texto, Clase* clase, Usuario* autor, bool esRaiz);
        ~Mensaje();
        bool esRaiz();
        Asignatura* getAsignatura();
        Clase* getClase();
        DtFecha* getFechaYHoraEnviado();
        std::string getTexto();
        std::string getId();
        std::set<Mensaje*> getHijos();
        /**
        Agrega una respuesta al mensaje
        @param m Mensaje en respuesta al mensaje actual
        */
        void agregarHijo(Mensaje* m);
        DtMensaje* toDt(); //crea un DT recursivamente
};

#endif
