#ifndef CTRLREPRODUCCION_H
#define CTRLREPRODUCCION_H

#include "ireproduccion.h"
#include <set>
#include <string>
#include "clase.h"
#include "estudiante.h"
#include "docente.h"
#include "handlerusuarios.h"


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
        /**
        Identifica al usuario actual, llama a getEstudiante(email)
        @param email el id para buscar al estudiante
        @param contrasenia la contrasenia del usuario (Decorativo?)
        @return Booleano que confirma que la identificacion funciono.
        */
        bool identificarse(std::string email, std::string contrasenia);
        /**
        @return Coleccion de DtAsignatura las asignaturas del estudiante actual
        */
        std::set<DtAsignatura*> listarAsignaturasEstudiante();
        /**
        Elige la asignatura de la cual listar clases, llama a getAsignatura() en Estudiante.
        @param codigo El codigo de la asignatura elegida.
        */
        void elegirAsignaturaEst(std::string codigo);
        /**
        @return coleccion de DtClase de la asignatura elegida para el estudiante actual.
        */
        std::set<DtClase*> listarClasesEstudiante();
        /**
        Elige la clase a reproducir
        */
        void elegirClase(std::string id);
        /**
        Muestra los datos de la clase elegida para confirmar.
        */
        DtClase* mostrarDatosClase();
        /**
        @return Coleccion de DtMensajes de la clase reproducida
        Debe crear la coleccion a partir de la coleccion de mensajes de la clase.
        */
        std::set<DtMensaje*> ListarMensajes();
        /**
        Confirma la asistencia a la clase.
        */
        void confirmarAsistenciaClaseEnVivo(bool confi);

        bool estaAsistiendo();
        
};
#endif