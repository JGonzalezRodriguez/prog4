#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>

class DtUsuario{
    private:
        std::string nombre;
        std::string email;
        std::string imagen;
        std::string contrasenia;
    public:
        DtUsuario(std::string nombre, std::string email, std::string imagen, std::string contrasenia);
        //El constructor nunca se usa solo ya que la clase no se instancia (es abstracta),
        //pero los constructores de cada uno de los hijos usaran este constructor (vease los cpp de DtDocente y DtEstudiante)
        virtual ~DtUsuario() = 0; //Funcion virtual pura; hace que la clase sea abstracta 
        std::string getNombre();
        std::string getEmail();
        std::string getImagen();
        std::string getContrasenia();
        //Notese que todas estas cosas estan definidas aca simplemente para no tener q definirlas dos veces en DtDocente y DtEstudiante. (se heredan)
};
#endif
