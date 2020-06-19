#ifndef USUARIO_H
#define USUARIO_H
#include <string> 
//#include "asignatura.h"
//#include "clase.h"
#include "mensaje.h"
#include "subscripcion.h"
#include "notificacion.h"
//#include "subscripcion.h"
#include <set>
#include "srespuesta.h"

class Asignatura;
class Clase;
//class Subscripcion;

class Usuario {
    private:
        std::string nombre;
        std::string email;
        std::string imagen;
        std::string contrasenia;
        std::set<Notificacion*> notificaciones;
        Subscripcion* subscripcion;
        //podrian haber mas links
    public:
    //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

       std::string getNombre();
       void setNombre(std::string);
       std::string getEmail();
       void setEmail(std::string);
       std::string getImagen();
       void setImagen(std::string);
       std::string getContrasenia();
       void setContrasenia(std::string);

       std::set<Notificacion*> listarNotificaciones();
       void eliminarNotificaciones();
       void eliminarNotificacionAsign(Asignatura *a);
       void elegirModo();
       void eliminarSubscripcion();
       virtual std::set<Clase*> listarClases() = 0;
       virtual Clase *elegirClase(std::string id);
       virtual bool tieneAsignatura(Asignatura *a) = 0;
       void notificarUsuario(Mensaje *m);
       virtual ~Usuario(); //no estoy seguro del destructor
       Usuario(std::string nombre, std::string email, std::string imagen, std::string contrasenia);
};
#endif