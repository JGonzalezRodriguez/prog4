#ifndef CTRLSUBSCRIPCION_H
#define CTRLSUBSCRIPCION_H

#include "isubscripcion.h"
#include "srespuesta.h"
#include "handlerusuarios.h"
#include "usuario.h"
#include <set>
// IMPORTAR DTS Y ENUMS

class CtrlSubscripcion : public ISubscripcion {
    private:
        static CtrlSubscripcion* instancia;
        Usuario* u;
        CtrlSubscripcion();
    public:
        static CtrlSubscripcion* getInstancia();
        void identificarse(string mail, string constrasenia);
        std::set<DtNotificacion*> listarNotificaciones();
        void eliminarNotificaciones();
        void elegirModo(modosubscripcion : modo);
        void eliminarSubscripcion();
}

#endif