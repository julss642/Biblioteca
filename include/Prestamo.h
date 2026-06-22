#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class Prestamo {
private:
    std::string nombrePersona;
    std::string tituloLibro;

public:
    Prestamo(std::string nombrePersona, std::string tituloLibro);

    void mostrarInformacion();
};

#endif