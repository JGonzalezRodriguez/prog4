#ifndef CTRLREPRODUCCION_H
#define CTRLREPRODUCCION_H

#include "IReproduccion.h"
#include <set>
#include "Clase.h"
#include "Estudiante.h"


#include "DtClase.h"
#include "DtAsignatura.h"
#include "DtMensaje.h"

class CtrlReproduccion : public IReproduccion {
    private:
        Estudiante est;
        static CtrlReproduccion instancia;
        Clase c;
        std::set<Clase> colclase;
        Asignatura a;
    public:
        ~CtrlReproduccion();
        static CtrlReproduccion getInstancia(){};
        void identificarse(std::string email, std::string contrasenia);
        std::set<DtAsignatura> listarAsignaturasEstudiante();
        void elegirAsignaturaEst(std::string codigo);
        std::set<DtClase> listarClasesEstudiante();
        void elegirClase(std::string id);
        DtClase mostrarDatosClase();
        std::set<DtMensaje> ListarMensajes();
};
#endif