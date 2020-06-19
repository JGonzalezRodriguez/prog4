#ifndef CTRLCLASE_H
#define CTRLCLASE_H
#include "asignatura.h"
#include "dt/dtfecha.h"
#include "dt/enums.h"
#include "dt/dtasignatura.h"
#include "dt/dtclase.h"
#include "dt/dtpreview.h"
#include <string> 
#include "iclase.h"
#include <set>
#include "handlerusuarios.h"//por dependencia
#include "dt/dttiempoasignatura.h"
#include "dt/dtpromasistencia.h"

//es singleton
class CtrlClase: public IClase{
    private:
        static CtrlClase *instancia;
        CtrlClase();//constructor privado
        std::string nombre;
        DtFecha *fecha;
        modalidad mod;
        Asignatura *asignatura;
        Docente *docente;
        std::set<Estudiante*> estudiantes;//recordar que el maximo del set es 15, chequearlo con un if al momento de implementar
        Clase* clase;
    public:
        static CtrlClase *getInstancia();

        std::string getNombre();
        void setNombre(std::string);
        DtFecha *getFecha();
        void setFecha(DtFecha*);
        void setModalidad(modalidad);
        
        void identificarse(std::string email, std::string contrasenia);
        std::set<DtAsignatura*> listarAsignaturasDocente();
        void inicioDeClase(std::string codigoasignatura, std::string nombre);
        modalidad getModalidad();
        std::set<DtEstudiante*> listarEstudiantesHabilitados();
        void elegirEstudiante(std::string ci);
        DtPreview* mostrarDatos();
        void confirmarInicioDeClase(bool conf);
        std::set<DtPreview*> listarClasesEnVivo();
        void elegirClase(std::string id);
        DtPreview* mostrarClase();
        void confirmarFinalizacionDeClase(bool conf);
        void elegirAsignaturaDoc(std::string codigo);
        std::set<DtClase*> listarClasesDocente();
        std::set<DtTiempoAsignatura*> tiempoDictadoClases();
        std::set<DtPromAsistencia*> promedioAsistencia();
        int tiempoTranscurrido(DtFecha *fechacomienzo, DtFecha *fechafin);
};

#endif