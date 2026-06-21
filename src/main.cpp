#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Libro.h"
#include "../include/Biblioteca.h"

using namespace std;

int main() {

    Biblioteca biblioteca;

    biblioteca.cargarBiblioteca();

    int opcion = 0;

    while(opcion != 7) {

        cout << "\n===== BIBLIOTECA =====" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar libros" << endl;
        cout << "3. Buscar libro" << endl;
        cout << "4. Eliminar libro" << endl;
        cout << "5. Guardar biblioteca" << endl;
        cout << "6. Modificar libro" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        switch(opcion) {

        case 1: {

            string titulo;
            string autor;
            int año;

            cin.ignore();

            cout << "Titulo: ";
            getline(cin, titulo);

            cout << "Autor: ";
            getline(cin, autor);

            cout << "Año: ";
            cin >> año;

            Libro nuevoLibro(titulo, autor, año );

            biblioteca.agregarLibro(nuevoLibro);

            cout << "Libro agregado correctamente." << endl;

            break;
        }

        case 2:

            // cout << "Cantidad de libros: "
                 // <<biblioteca.size()
                 // << endl;

            biblioteca.mostrarLibros();

            break;

        case 3: {

            string tituloBuscado;

            cin.ignore();

            cout << "Titulo a buscar: ";
            getline(cin, tituloBuscado);

            biblioteca.buscarLibro(tituloBuscado);

            break;
        }

        case 4: {

            string tituloEliminar;

            cin.ignore();

            cout << "Titulo a eliminar: ";
            getline(cin, tituloEliminar);

            biblioteca.eliminarLibro(tituloEliminar);

            break;
        }

        case 5: {

            biblioteca.guardarBiblioteca();

            break;
        }

        case 6: {

            string tituloBuscado;

            cin.ignore();

            cout << "Titulo a modificar: ";
            getline(cin, tituloBuscado);

            biblioteca.modificarLibro(tituloBuscado);

            break;
        }

        case 7:
           cout << "Hasta luego" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}