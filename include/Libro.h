#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    int año;

public:
    std::string getTitulo();
    std::string getAutor();
    int getAño();

    void setAutor(std::string nuevoAutor);
    void setAño(int nuevoAño);

    Libro(std::string titulo, std::string autor, int año);

    void mostrarInformacion();
};

#endif