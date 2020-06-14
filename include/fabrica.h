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

class Fabrica {
    private:
        static IAsignatura* instasignatura;
        static IClase* instclase;
        static IMensaje* instmensaje;
        static IReproduccion* instreproduccion;
        static ISubscripcion* instsubscripcion;
        static IUsuario* instusuario;
    public:
        static IAsignatura* getIAsignatura();
        static IClase* getIClase();
        static IMensaje* getIMensaje();
        static IReproduccion* getIReproduccion();
        static ISubscripcion* getISubscripcion();
        static IUsuario* getIUsuario();
};