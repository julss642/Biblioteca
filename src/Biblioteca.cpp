#include "../include/Biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Biblioteca::agregarLibro(Libro libro) {

    libros.push_back(libro);
}

void Biblioteca::mostrarLibros() {

    if(libros.empty()) {

        cout << "No hay libros registrados." << endl;

        return;
    }

    for(Libro libro : libros) {

        libro.mostrarInformacion();

        cout << endl;
    }
}

void Biblioteca::buscarLibro(string titulo) {

    bool encontrado = false;

    for(Libro libro : libros) {

        if(libro.getTitulo() == titulo) {

            libro.mostrarInformacion();

            encontrado = true;
        }
    }

    if(!encontrado) {

        cout << "Libro no encontrado." << endl;
    }
}

void Biblioteca::eliminarLibro(string titulo) {

    bool eliminado = false;

    for(int i = 0; i < libros.size(); i++) {

                if(libros[i].getTitulo() == titulo) {

                    libros.erase(libros.begin() + i);

                    eliminado = true;

                    cout << "Libro eliminado correctamente." << endl;

                    break;
                }
            }

            if(!eliminado) {

                cout << "Libro no encontrado." << endl;

            }
}

void Biblioteca::guardarBiblioteca() {

    ofstream archivo("../libros.txt");

    for(Libro libro : libros) {

        archivo << libro.getTitulo()
                << ";"
                << libro.getAutor()
                << ";"
                << libro.getAño()
                << endl;
    }

    archivo.close();

    cout << "Biblioteca guardada correctamente." << endl;
}

void Biblioteca::cargarBiblioteca() {

    ifstream archivo("../libros.txt");

    string linea;

    while(getline(archivo, linea)) {

        string titulo;
        string autor;
        string añoTexto;

        stringstream ss(linea);

        getline(ss, titulo, ';');
        getline(ss, autor, ';');
        getline(ss, añoTexto, ';');

        int año = stoi(añoTexto);

        Libro libro(titulo, autor, año);

        libros.push_back(libro);
    }

    archivo.close();
}

void Biblioteca::modificarLibro(string titulo) {

    bool encontrado = false;

    for(int i =0; i < libros.size(); i++) {

        if(libros[i].getTitulo() == titulo) {

            string nuevoAutor;
            int nuevoAño;

            cout << "Nuevo autor: ";
            getline(cin, nuevoAutor);

            cout << "Nuevo año: ";
            cin >> nuevoAño;

            libros[i].setAutor(nuevoAutor);
            libros[i].setAño(nuevoAño);

            encontrado = true;

            cout << "Libro modificado correctamente." << endl;

            break;
        }
    }

    if(!encontrado) {

        cout << "Libro no encontrado." << endl;
    }
}