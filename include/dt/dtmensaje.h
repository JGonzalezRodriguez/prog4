#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <string>
#include <set>
#include "dtfecha.h"

class DtMensaje{
    private:
        std::string texto;
        std::string id;
        std::string autor;
        DtFecha* fechayhora;
        std::set<DtMensaje*> respuestas;
    public:
        DtMensaje(std::string texto, DtFecha* fechayhora, std::string id, std::string autor, std::set<DtMensaje*> respuestas);
        ~DtMensaje();
        std::string getTexto();
        std::string getId();
        std::string getAutor();
        DtFecha* getFechaYHora();
        std::set<DtMensaje*> getRespuestas();
        void recursivePrint(int iter);
};
std::ostream& operator<< (std::ostream& os, DtMensaje&b);
#endif
