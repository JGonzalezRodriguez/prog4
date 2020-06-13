#ifndef HANDLERUSUARIOS_H
#define HANDLERUSUARIOS_H
#include "usuario.h"
#include <string> 
#include "mensaje.h"
#include "asignatura.h"
#include <set>


//es singleton
class Handlerusuarios{
    private:
        static Handlerusuarios *instancia;
        Handlerusuarios();
        std::set<Estudiante*> estudiantes;
        std::set<Docente*> docentes;
        std::set<Usuario*> usuariosubs;
    public:
        static Handlerusuarios *getInstancia();
        void add(Usuario *u)
        std::set<Docente*> getDocentes();
        Docente *getDocente(std::string email); 
        bool identificarse(std::string email, std::string contrasenia);
        Estudiante *getEstudiante(std::string email);
        Usuario *getUsuario(std::string email);
        void notificar(Asignatura *a, Mensaje *m);
        void addSubscripto(Usuario *u);
        void removerSubscripto(Usuario *u);
};

#endif