#ifndef CTRLCLASE_H
#define CTRLCLASE_H
#include "asignatura.h"
#include "dtfecha.h"
#include "modalidad.h"
#include <string> 
#include "iclase.h"
#include <set>
#include "handlerusuarios.h"//por dependencia

//es singleton
class Ctrlclase: public IClase{
    private:
        static Ctrlclase *instancia;
        Ctrlclase();//constructor privado
        string nombre;
        DtFecha *fecha;
        modalidad mod;
        Asignatura *asignatura;
        Docente *docente;
        std::set<Estudiante*> estudiantes;//recordar que el maximo del set es 15, chequearlo con un if al momento de implementar
    public:
        static Ctrlclase *getInstancia();

        String getNombre();
        void setNombre(string);
        DtFecha *getFecha();
        void setFecha(DtFecha*);
        modalidad getMod();
        void setMod(modalidad);
        
        void identificarse(string email, string contrasenia);
        std::set<DtAsignatura*> listarAsignaturasDocente();
        void inicioDeClase(string codigoasignatura, string nombre, DtFecha *fecha);
        modalidad getModalidad();
        std::set<DtEstudiante*> listarEstudiantesHabilatados();
        void elegirEstudiante(string ci);
        DtClase *mostrarDatos();
        void confirmarInicioDeClase(bool conf);
        std::set<DtClase*> listarClasesEnVivo();
        void elegirClase(string id);
        DtClase *mostrarClase();
        void confirmarFinalizacionDeClase(bool conf);
        void elegirAsignaturaDoc(string codigo);
        std::set<DtClase*> listarClasesDocente();
};

#endif