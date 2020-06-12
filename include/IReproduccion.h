#ifndef IREPRODUCCION_H
#define IREPRODUCCION_H

#include <string>
#include <map>
#include <set>

#include "DtAsignatura.h"
#include "DtClase.h"
#include "DtMensaje.h"



class IReproduccion {
    private:

    public:
    virtual IReproduccion getInstancia() = 0;
    virtual void identificarse(std::string email, std::string contrasenia) = 0;
    virtual std::set<DtAsignatura> listarAsignaturasEstudiante() = 0;
    virtual void elegirAsignaturaEst(std::string codigo) = 0;
    virtual std::set<DtClase> listarClasesEstudiante() = 0;
    virtual void elegirClase(std::string id) = 0;
    virtual DtClase mostrarDatosClase() = 0;
    // virtual void confirmarReproduccionClaseEnDiferido(bool: confi);   #Esta no va si no hay reproduccion en diferido?
    virtual std::set<DtMensaje> ListarMensajes() = 0;

};

#endif