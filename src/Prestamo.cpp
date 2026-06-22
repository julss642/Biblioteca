#include "../include/Prestamo.h"
#include <iostream>

using namespace std;

Prestamo::Prestamo(string nombrePersona, string tituloLibro) {

    this->nombrePersona = nombrePersona;
    this->tituloLibro = tituloLibro;
}

void Prestamo::mostrarInformacion() {

    cout << "Persona: " << nombrePersona << endl;
    cout << "Libro: " << tituloLibro << endl;
}