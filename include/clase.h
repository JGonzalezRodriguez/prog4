#ifndef CLASE_H
#define CLASE_H
#include <estudiante.h>
#include <claseestudiante.h>
#include <mensaje.h>
#include <asignatura.h>
#include <docente.h>
#include "dtfecha.h"
#include <set>

class Clase{
    private:
        DtFecha *fechayhoracomienzo;
        string id;
        bool envivo;
        DtFecha *fechayhorafinal;
        string url;
        string nombre;
        Asignatura *asignatura;
        std::set<Claseestudiante*> claseestudiantes;
        std::set<Mensaje*> mensajes;
        Docente *docente;
    public:
        DtFecha *getFechayhoracomienzo();
        void setFechayhoracomienzo(DtFecha*);
        string getId();
        void setId(string);
        bool getEnvivo();
        void setEnvivo(bool);
        DtFecha *getFechayhorafinal();
        void setFechayhorafinal(DtFecha*);
        string getUrl();
        void setUrl(string);
        string getNombre();
        void setNombre(string);

        
        Asignatura *getAsignatura();
        bool getEnVivo();
        void finalizar();
        bool tieneClaseEst(Estudiante *est);
        Claseestudiante *crearClaseEst(Estudiante *est, Clase *c);
        Claseestudiante *getClaseEstExistente();
        std::set<Mensaje*> getMensajes();
        Mensaje seleccionarMensaje(string idmensaje);
        void agregarPadre(Mensaje *m);

        //constructor
        Clase(string nombre, DtFecha *fecha, Asignatura *asignatura, Docente *doc);
};

#endif