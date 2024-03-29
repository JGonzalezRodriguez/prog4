#include "iasignatura.h"
#include "iclase.h"
#include "imensaje.h"
#include "ireproduccion.h"
#include "isubscripcion.h"
#include "iusuario.h"
#include "ctrlasignatura.h"
#include "ctrlclase.h"
#include "ctrlmensaje.h"
#include "ctrlreproduccion.h"
#include "ctrlsubscripcion.h"
#include "ctrlusuario.h"

//TODO: singleton o no instanciable? si es singleton xq los metodos son static?
class Fabrica {
    private:
        static Fabrica *instancia;
        Fabrica();
        
    public:
        static Fabrica* getInstancia();
        static IAsignatura* getIAsignatura();
        static IClase* getIClase();
        static IMensaje* getIMensaje();
        static IReproduccion* getIReproduccion();
        static ISubscripcion* getISubscripcion();
        static IUsuario* getIUsuario();
};