#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <set>
#include "dtfecha.h"
#include "dtasignatura.h"

class DtNotificacion{
    private:
        DtFecha* fechayhoraenviado;
        std::string nombreautor;
        std::string textomsj;
        std::string nombreclase;
        std::string idclase;
        DtAsignatura* asignatura;
    public:
        DtNotificacion(DtFecha* fechayhoraenviado, std::string nombreautor, std::string textomsj, std::string nombreclase, std::string idclase, DtAsignatura* asignatura);
        ~DtNotificacion();
        DtFecha* getFechaYHoraEnviado();
        std::string getNombreClase();
        std::string getIdClase();
        DtAsignatura* getAsignatura();
        std::string getNombreAutor();
        std::string getTextoMsj();
};

std::ostream& operator<< (std::ostream& os, DtNotificacion &b);

#endif
