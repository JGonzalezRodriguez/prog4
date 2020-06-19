#ifndef CLASE_H
#define CLASE_H

#include <claseestudiante.h>
#include <mensaje.h>
#include <asignatura.h>
#include "dt/dtfecha.h"
#include <set>
#include <string>
#include <estudiante.h>

class Docente;
//class Estudiante;
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
        virtual DtFecha *getFechayhoracomienzo();
        virtual void setFechayhoracomienzo(DtFecha*);
        virtual void setId(std::string);
        virtual void setEnVivo(bool);
        virtual DtFecha *getFechayhorafinal();
        virtual void setFechayhorafinal(DtFecha*);
        virtual std::string getUrl();
        virtual void setUrl(std::string);
        virtual std::string getNombre();
        virtual void setNombre(std::string);
        Docente* getDoc();
        
        virtual void setDocente(Docente* doc);
        virtual Docente* getDocente();
        virtual Asignatura *getAsignatura();
        virtual bool getEnVivo();
        virtual void finalizar();
        virtual bool tieneClaseEst(Estudiante *est);
        virtual ClaseEstudiante *crearClaseEst(Estudiante *est, Clase *c);
        virtual ClaseEstudiante *getClaseEstExistente(Estudiante *est);
        virtual std::set<Mensaje*> getMensajes();
        virtual std::string getId();
        virtual Mensaje* seleccionarMensaje(std::string idmensaje);
        virtual void agregarPadre(Mensaje *m);

        Clase(std::string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
        virtual ~Clase() = 0;
};

#endif