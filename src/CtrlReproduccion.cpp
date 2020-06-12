
#include "../include/CtrlReproduccion.h"
#include <set>

class CtrlReproduccion : public IReproduccion {
    private:
        Estudiante est;
        CtrlReproduccion instancia;
        Clase c;
        std::set<Clase> colclase;
        Asignatura a;
    public:
        ~CtrlReproduccion();
        IReproduccion getInstancia() {
            return instancia;
        }
        void identificarse(std::string email, std::string contrasenia){
            //todo
        }
        std::set<DtAsignatura> listarAsignaturasEstudiante(){
            //todo
            return trash = new set<DtAsignatura>;
        }
        void elegirAsignaturaEst(std::string codigo){
            //todo
        }
        std::set<DtClase> listarClasesEstudiante(){
            //todo
            return trash = new set<DtClase>;
        }
        void elegirClase(std::string id){
            //todo
        }
        DtClase mostrarDatosClase(){
            return trash = new DtClase;
        }
        // void confirmarReproduccionClaseEnDiferido(bool: confi);   #Esta no va si no hay reproduccion en diferido?
        std::set<DtMensaje> ListarMensajes(){
            //todo
            return trash = new set<DtMensaje>;
        }
};