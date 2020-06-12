#include "../include/Dicta.h"

class Dicta {
    private:   
        modalidad modalidad;
        Asignatura* asig;
        Docente* doc;
        Dicta();
    public:
        Dicta(modalidad modalidad, Docente* doc, Asignatura* asig){
            Dicta dicta_nuevo = new Dicta;
            dicta_nuevo.modalidad = modalidad;
            dicta_nuevo.doc = doc;
            dicta_nuevo.asig = asig;
            return dicta_nuevo;
        };
        
        Docente getDocente(){
            return &this->doc;
        };

        void deslinkearDocente() {
        };

        Asignatura getAsignatura() {
            return &this->asig;
        };

        modalidad getModalidad() {
            return this->modalidad;
        };
};

Dicta::~Dicta() {
    this->doc = NULL;
    this->asig = NULL;
    delete this; //tire cualquiera?
}