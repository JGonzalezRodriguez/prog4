#ifndef USUARIO_H
#define USUARIO_H
#include <string> 
#include "asignatura.h"
#include "clase.h"
#include "mensaje.h"
#include "subscripcion.h"
#include <set>

class Usuario{
    private:
        string nombre;
        string email;
        string imagen;
        string contraseña;
        std::set<Notificacion*> notificaciones;
        Subscripcion *subscripcion;
        //podrian haber mas links
    public:
    //posiblemente haya que poner punteros a los parametros de las operaciones que sean de tipo otra clase

       string getNombre();
       void setNombre(string);
       string getEmail();
       void setEmail(string);
       string getImagen();
       void setImagen(string);
       string getContrasenia();
       void setContrasenia(string);

       std::set<Notificacion*> listarNotificaciones();
       void eliminarNotificaciones();
       void eliminarNotificacionAsign(Asignatura *a);
       void elegirModo(subscripcion *subscripcion);
       void eliminarSubscripcion();
       virtual std::set<Clase*> listarClases() = 0;
       Clase *elegirClase(string id);
       virtual bool tieneAsignatura(Asignatura *a) = 0;
       void notificarUsuario(Mensaje *m);
       virtual ~Usuario(); //no estoy seguro del destructor
       Usuario(string nombre, string email, string imagen, string contrasenia);
};
#endif