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
class Ctrlusuario: public IUsuario{
    private:
        static Ctrlusuario *instancia;
        Ctrlusuario();
        string nombre;
        string email;
        string contrasenia;
        string imagen; //en el dcd esta como url pero le puse imagen para que sea consistente con usuario
        instituto instituto;
        string ci;
        bool esdocente;
    public:
        string getNombre();
        void setNombre(string);
        string getEmail();
        void setEmail(string);
        string getImagen();
        void setImagen(string);
        string getContrasenia();
        void setContrasenia(string);
        instituto getInstituto();
        void setInstituto(instituto);
        string getCi();
        void setCi(string);
        bool getEsdocente();
        void setEsdocente(bool);
        
        static Ctrlusuario *getInstancia();
        void altaDocente(string nombre, string email, string contrasenia, string imagen, instituto instituto);
        void altaEstudiante(string nombre, string email, string contrasenia, string imagen, string ci);
        void confirmarAltaUsuario(bool conf);
};


#endif