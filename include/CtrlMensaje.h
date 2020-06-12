#ifndef CTRLMENSAJE_H
#define CTRLMENSAJE_H

#include <string>
#include <set>
#include "Usuario.h"
#include "Clase.h"
#include "DtClase.h"
#include "Mensaje.h"
#include "DtMensaje.h"

class CtrlMensaje{
    private:
        static CtrlMensaje* instancia;
        Usuario* u;
        Clase* c;
        Mensaje* m;
        std::string texto;
    public:
        CtrlMensaje();
        ~CtrlMensaje();
        static CtrlMensaje* getInstancia();
        Usuario* getUsuario();
        Clase* getClase();
        Mensaje* getMensaje();
        setUsuario(Usuario* u);
        setClase(Clase* c);
        setMensaje(Mensaje* m);
        void identificarse(std::string mail, std::string contrasenia);
        std::set<DtClase*> listarClases();
        void elegirClase(std::string id);
        std::set<DtMensaje*> listarMensajes();
        void seleccionarMensaje(std::string idMensaje);
        void textoEnviar(std::string texto);
        void confirmarEnvioMensaje(bool conf);
};

#endif
