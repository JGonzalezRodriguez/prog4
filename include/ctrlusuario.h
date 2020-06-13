#ifndef CTRLUSUARIO_H
#define CTRLUSUARIO_H
#include <string>
#include "iusuario.h"
#include "instituto.h"
#include <set>
#include "handlerusuarios.h"//dependencia
#include "estudiante.h"//dependencia
#include "docente.h"//dependencia


//es singleton
class CtrlUsuario: public IUsuario{
    private:
        static CtrlUsuario *instancia;
        CtrlUsuario();
        std::string nombre;
        std::string email;
        std::string contrasenia;
        std::string imagen; //en el dcd esta como url pero le puse imagen para que sea consistente con usuario
        instituto inst;
        std::string ci;
        bool esdocente;
    public:
        std::string getNombre();
        void setNombre(std::string);
        std::string getEmail();
        void setEmail(std::string);
        std::string getImagen();
        void setImagen(std::string);
        std::string getContrasenia();
        void setContrasenia(std::string);
        instituto getInstituto();
        void setInstituto(instituto);
        std::string getCi();
        void setCi(std::string);
        bool getEsdocente();
        void setEsdocente(bool);
        
        static CtrlUsuario *getInstancia();
        void altaDocente(std::string nombre, std::string email, std::string contrasenia, std::string imagen, instituto inst);
        void altaEstudiante(std::string nombre, std::string email, std::string contrasenia, std::string imagen, std::string ci);
        void confirmarAltaUsuario(bool conf);
};


#endif