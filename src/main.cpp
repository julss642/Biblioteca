#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Libro.h"

using namespace std;

int main() {

    vector<Libro> biblioteca;

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

        biblioteca.push_back(libro);

    }

    archivo.close();

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

            biblioteca.push_back(nuevoLibro);

            cout << "Libro agregado correctamente." << endl;

            break;
        }

        case 2:

            cout << "Cantidad de libros: "
                 <<biblioteca.size()
                 << endl;

            if(biblioteca.empty()) {

                cout << "No hay libros registrados." << endl;

            } else {

                for(Libro libro : biblioteca) {

                    libro.mostrarInformacion();
                    cout << endl;
                }
            }

            break;

        case 3: {

            string tituloBuscado;

            cin.ignore();

            cout << "Titulo a buscar: ";
            getline(cin, tituloBuscado);

            bool encontrado = false;

            for(Libro libro : biblioteca) {

                if(libro.getTitulo() == tituloBuscado) {

                    libro.mostrarInformacion();

                    encontrado = true;
                }       
            }

            if(!encontrado) {

                cout << "Libro no encontrado." << endl;
            }

            break;
        }

        case 4: {

            string tituloEliminar;

            cin.ignore();

            cout << "Titulo a eliminar: ";
            getline(cin, tituloEliminar);

            bool eliminado = false;

            for(int i = 0; i < biblioteca.size(); i++) {

                if(biblioteca[i].getTitulo() == tituloEliminar) {

                    biblioteca.erase(biblioteca.begin() + i);

                    eliminado = true;

                    break;
                }
            }

            if(!eliminado) {
                cout << "Libro no encontrado." << endl;
            }

            break;
        }

        case 5: {
            ofstream archivo("../libros.txt");
            for(Libro libro : biblioteca){
                archivo << libro.getTitulo()
                    << ";"
                    << libro.getAutor()
                    << ";"
                    << libro.getAño()
                    << endl;
            }

            archivo.close();

            cout << "Biblioteca guardada correctamente." << endl;
            break;
        }

        case 6: {

            string tituloBuscado;

            cin.ignore();

            cout << "Titulo a modificar: ";
            getline(cin, tituloBuscado);

            bool encontrado = false;

            for(Libro &libro : biblioteca) {

                if(libro.getTitulo() == tituloBuscado) {

                    string nuevoAutor;
                    int nuevoAño;

                    cout << "Nuevo autor: ";
                    getline(cin, nuevoAutor);

                    cout << "Nuevo año: ";
                    cin >> nuevoAño;

                    libro.setAutor(nuevoAutor);
                    libro.setAño(nuevoAño);

                    cout << "Libro actualizado correctamente." << endl;

                    encontrado = true;

                    break;
                }
            }

            if(!encontrado) {

                cout << "Libro no encontrado." << endl;
            }

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