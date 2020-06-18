#ifndef CTRLSUBSCRIPCION_H
#define CTRLSUBSCRIPCION_H

#include "isubscripcion.h"
#include "srespuesta.h"
#include "handlerusuarios.h"
#include "usuario.h"
#include <set>
// IMPORTAR DTS Y ENUMS
#include "dt/dtnotificacion.h"

class CtrlSubscripcion : public ISubscripcion {
    private:
        static CtrlSubscripcion* instancia;
        Usuario* u;
        CtrlSubscripcion();
        bool identifico;
    public:
        static CtrlSubscripcion* getInstancia();
        /**
        Identifica al usuario y lo recuerda como el usuario actual.
        */
        void identificarse(std::string mail, std::string constrasenia);
        /**
        @return Coleccion de notificaciones del usuario actual.
        */
        std::set<DtNotificacion*> listarNotificaciones();
        /**
        Elimina las notificacion del usuario actual.
        */
        void eliminarNotificaciones();
        /**
        Cambia el modo de subscripcion del usuario actual.
        @param modo El nuevo modo de subscripcion.
        */
        void elegirModo();
        /**
        Elimina el puntero a subscripcion del usuario actual.
        */
        void eliminarSubscripcion();

        bool getIdentifico();

        
};

#endif