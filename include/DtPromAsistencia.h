#ifndef DTPROMASISTENCIA_H
#define DTPROMASISTENCIA_H

#include <string>

class DtPromAsistencia{
    private:
        std::string clase;
        int tiempoprom;
    public:
        DtPromAsistencia(std::string clase, int tiempoprom);
        ~DtPractico();
        std::string getClase();
        int getTiempoProm();
};
#endif
