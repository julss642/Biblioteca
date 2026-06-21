#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"

class Biblioteca {

private:

    std::vector<Libro> libros;

public:

    void agregarLibro(Libro libro);
    void mostrarLibros();
    void buscarLibro(std::string titulo);
    void eliminarLibro(std::string titulo);
    void guardarBiblioteca();
    void cargarBiblioteca();
    void modificarLibro(std::string titulo);

};

#endif