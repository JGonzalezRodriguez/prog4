#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>

class IUsuario {
    public:
    virtual void altaDocente(std::string nombre, std::string email, std::string contrasenia, std::string url, enum instituto) = 0;
    virtual void altaEstudiante(std::string nombre, std::string email, std::string contrasenia, std::string url, std::string ci) = 0;
    virtual void confirmarAltaUsuario(bool conf) = 0;
    virtual ~IUsuario() { };
};

#endif