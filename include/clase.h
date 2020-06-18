#ifndef CLASE_H
#define CLASE_H

#include <claseestudiante.h>
#include <mensaje.h>
#include <asignatura.h>
#include "dt/dtfecha.h"
#include <set>
#include <string>
//#include <estudiante.h>

class Docente;
class Estudiante;
class ClaseEstudiante;
class Mensaje;

class Clase {
    private:
        static int seed;
        DtFecha *fechayhoracomienzo;
        std::string id;
        bool envivo;
        DtFecha *fechayhorafinal;
        std::string url;
        std::string nombre;
        Asignatura* asig;
        std::set<ClaseEstudiante*> claseestudiantes;
        std::set<Mensaje*> mensajes;
        Docente* doc;
    public:
        static int getSeed();
        static void incSeed();
        DtFecha *getFechayhoracomienzo();
        void setFechayhoracomienzo(DtFecha*);
        void setId(std::string);
        void setEnVivo(bool);
        DtFecha *getFechayhorafinal();
        void setFechayhorafinal(DtFecha*);
        std::string getUrl();
        void setUrl(std::string);
        std::string getNombre();
        void setNombre(std::string);
        Docente* getDoc();

        
        Asignatura *getAsignatura();
        bool getEnVivo();
        void finalizar();
        bool tieneClaseEst(Estudiante *est);
        ClaseEstudiante *crearClaseEst(Estudiante *est, Clase *c);
        ClaseEstudiante *getClaseEstExistente();
        std::set<Mensaje*> getMensajes();
        std::string getId();
        Mensaje* seleccionarMensaje(std::string idmensaje);
        void agregarPadre(Mensaje *m);

        Clase(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};

#endif