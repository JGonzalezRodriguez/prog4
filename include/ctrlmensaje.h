#ifndef CTRLMENSAJE_H
#define CTRLMENSAJE_H

#include <string>
#include <set>
#include "usuario.h"
#include "clase.h"
#include "dt/dtclase.h"
#include "mensaje.h"
#include "dt/dtmensaje.h"
#include "imensaje.h"

class CtrlMensaje: public IMensaje{
    private:
        static CtrlMensaje* instancia;
        Usuario* u;
        Clase* c; 
        Mensaje* m;
        std::string texto;
        CtrlMensaje();
    public:
        ~CtrlMensaje();
        static CtrlMensaje* getInstancia();
        Usuario* getUsuario();
        Clase* getClase();
        Mensaje* getMensaje();
        void setUsuario(Usuario* u);
        void setClase(Clase* c);
        void setMensaje(Mensaje* m);
        void identificarse(std::string mail, std::string contrasenia);
        /**
        Genera una col(DtClase) a partir de una col(DtClase)
        @return coleccion de DtClases a las que asistio el usuario
        */
        std::set<DtClase*> listarClases();
        void elegirClase(std::string id);
        /**
        Crea una col(DtMensaje) a partir de la col(Mensaje) de la clase seleccionada.
        @return col(DtMensaje)
        */
        std::set<DtMensaje*> listarMensajes();
        /**
        Selecciona el mensaje a responder. Dejar en blanco si no es respuesta a nadie?
        @param idMensaje id del mensaje a responder.
        */
        void seleccionarMensaje(std::string idMensaje);
        /**
        Guarda el texto a enviar en el mensaje.
        */
        void textoEnviar(std::string texto);
        /**
        Guarda el mensaje en la clase mensaje. En caso de ser respuesta lo guarda en la col(Mensaje) de respuestas a un mensaje.
        */
        void confirmarEnvioMensaje(bool conf, bool esRaiz);
};

#endif
