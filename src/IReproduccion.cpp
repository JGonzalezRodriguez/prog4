#include "../include/IReproduccion.h"

class IReproduccion {
    private:

    public:
    virtual void getInstancia() = 0;
    virtual void identificarse(std::string email, std::string contrasenia) = 0;
    virtual std::set<DtAsignatura> listarAsignaturasEstudiante() = 0;
    virtual void elegirAsignaturaEst(std::string codigo) = 0;
    virtual std::set<DtClase> listarClasesEstudiante() = 0;
    virtual void elegirClase(std::string id) = 0;
    virtual DtClase mostrarDatosClase() = 0;
    // virtual void confirmarReproduccionClaseEnDiferido(bool: confi);   #Esta no va si no hay reproduccion en diferido?
    virtual std::set<DtMensaje> ListarMensajes() = 0;

};