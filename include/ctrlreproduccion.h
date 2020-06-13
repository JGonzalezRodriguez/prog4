#ifndef CTRLREPRODUCCION_H
#define CTRLREPRODUCCION_H

#include "ireproduccion.h"
#include <set>
#include <string>
#include "clase.h"
#include "estudiante.h"


#include "dt/dtclase.h"
#include "dt/dtasignatura.h"
#include "dt/dtmensaje.h"

class CtrlReproduccion : public IReproduccion {
    private:
        Estudiante* est;
        static CtrlReproduccion* instancia;
        Clase* c;
        std::set<Clase*> colclase;
        Asignatura* a;
        CtrlReproduccion();
    public:
        static CtrlReproduccion* getInstancia();
        void identificarse(std::string email, std::string contrasenia);
        std::set<DtAsignatura*> listarAsignaturasEstudiante();
        void elegirAsignaturaEst(std::string codigo);
        std::set<DtClase*> listarClasesEstudiante();
        void elegirClase(std::string id);
        DtClase* mostrarDatosClase();
        std::set<DtMensaje*> ListarMensajes();
};
#endif