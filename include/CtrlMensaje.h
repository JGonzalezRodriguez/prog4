#ifndef CTRLMENSAJE_H
#define CTRLMENSAJE_H

#include <string>
#include <set>
#include "usuario.h"
#include "clase.h"
#include "dt/dtclase.h"
#include "mensaje.h"
#include "dtmensaje.h"
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
        std::set<DtClase*> listarClases();
        void elegirClase(std::string id);
        std::set<DtMensaje*> listarMensajes();
        void seleccionarMensaje(std::string idMensaje);
        void textoEnviar(std::string texto);
        void confirmarEnvioMensaje(bool conf);
};

#endif
