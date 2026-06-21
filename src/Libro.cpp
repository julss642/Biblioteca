#include "../include/Libro.h"
#include <iostream>

using namespace std;

Libro::Libro(string titulo, string autor, int año) {
    this->titulo = titulo;
    this->autor = autor;
    this->año = año;
}

void Libro::mostrarInformacion() {
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Año: " << año << endl;
}

string Libro::getTitulo() {

    return titulo;
}

std::string Libro::getAutor() {

    return autor;
}

int Libro::getAño() {

    return año;
}

void Libro::setAutor(std::string nuevoAutor) {

    autor = nuevoAutor;
}

void Libro::setAño(int nuevoAño) {

    año = nuevoAño;
}