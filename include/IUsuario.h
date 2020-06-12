#ifndef IUSUARIO_H
#define IUSUARIO_H

class IUsuario {
    private:

    public:

    virtual IUsuario getInstancia() = 0;
    virtual void altaDocente(std::string nombre, std::string email, std::string contrasenia, std::string url, enum instituto) = 0;
    virtual void altaEstudiante(std::string nombre, std::string email, std::string contrasenia, std::string url, std::string ci) = 0;
    virtual void confirmar(conf: bool) = 0;

}



#endif