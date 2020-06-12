#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <string>
#include <set>
#include "DtFecha.h"

class DtMensaje{
    private:
        std::string texto;
        DtFecha* fechayhora;
        std::set<DtMensaje*> respuestas;
    public:
        DtMensaje(std::string texto, DtFecha* fechayhora, std::set<DtMensaje*> respuestas);
        ~DtMensaje();
        std::string getTexto();
        DtFecha* getFechaYHora();
        std::set<DtMensaje*> getRespuestas();
};
#endif
