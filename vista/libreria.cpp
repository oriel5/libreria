#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "Libreria.h"

using namespace std;

int main() {
    int menu, id_libro = 0, cantidad = 0;
    double precio = 0;
    string titulo, autor, fecha_publicacion, genero;

    //fecha calendario
    tm tiempo{};

    //validar datos
    string cad;
    stringstream mystream(cad);

    Libreria l = Libreria(id_libro, titulo, autor, fecha_publicacion, genero, precio, cantidad);

    system("title Libreria: Menu");
    system("color 0a");

    
    cout << setw(100) << setfill('=') << "=" << endl;
    cout << setfill(' ');
    cout << endl;
    cout << "                        // Bienvenido a la base de datos de la Libreria // " << endl;
    cout << endl;
    cout << setw(100) << setfill('=') << "=" << endl;
    cout << setfill(' ');


    while (true) {
        cout << "\n1. Buscar \n2. Agregar\n3. Editar\n4. Eliminar por ID\n5. Salir" << endl;
        cout << endl;

        while (true) {
            cout << "Eleccion: ";
            getline(cin, cad);
            stringstream mystream(cad);

            if (mystream >> menu and menu > 0 and menu < 6) { break; }
            cout << "Error: ingrese un numero disponible" << endl;

        }

        switch (menu) {

        case 1:
            system("title Libreria: Busqueda");
            system("cls");

            l.Buscar();

        break;

        case 2:
            system("title Libreria: Creando");
            system("cls");

            cout << "Ingrese el titulo del libro: ";
            getline(cin, titulo);

            cout << "Ingrese el autor: ";
            getline(cin, autor);

            
            
            while (true) {
                cout << "Ingrese la fecha de publicacion (YYYY-MM-DD): ";
                cin >> fecha_publicacion;

                stringstream ss(fecha_publicacion);

                if (ss >> get_time(&tiempo, "%Y-%m-%d")) { break; }
                cout << "Error: la fecha tiene que ser en formato adecuado" << endl;
            
            }

            cin.ignore();

            cout << "Ingrese el genero: ";
            getline(cin, genero);

            while (true) {
                cout << "Ingrese el precio: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> precio and precio > 0) { break; }
                cout << "Error: ingrese un numero real y mayor a cero" << endl;

            }

            while (true) {
                cout << "Ingrese la cantidad existente: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> cantidad and cantidad > -1) { break; }
                cout << "Error: ingrese un numero mayor que cero" << endl;

            }

            l.setId_libro(id_libro);
            l.setTitulo(titulo);
            l.setAutor(autor);
            l.setFecha_publicacion(fecha_publicacion);
            l.setGenero(genero);
            l.setPrecio(precio);
            l.setCantidad(cantidad);

            l.Crear();

        break;

        case 3:
            system("title Libreria: Editando");
            system("cls");


            while (true) {
                cout << "Ingrese el id del libro a editar: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> id_libro and id_libro > 0) { break; }
                cout << "Error: ingrese un numero mayor a cero" << endl;

            }

            cout << "Ingrese el titulo del libro: ";
            getline(cin, titulo);

            cout << "Ingrese el autor: ";
            getline(cin, autor);

            while (true) {
                cout << "Ingrese la fecha de publicacion (YYYY-MM-DD): ";
                cin >> fecha_publicacion;

                stringstream ss(fecha_publicacion);

                if (ss >> get_time(&tiempo, "%Y-%m-%d")) { break; }
                cout << "Error: la fecha tiene que ser en formato adecuado" << endl;

            }
            cin.ignore();


            cout << "Ingrese el genero: ";
            getline(cin, genero);

            while (true) {
                cout << "Ingrese el precio: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> precio and precio > 0) { break; }
                cout << "Error: ingrese un numero real" << endl;

            }

            while (true) {
                cout << "Ingrese la cantidad existente: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> cantidad and cantidad > -1) { break; }
                cout << "Error: ingrese un numero mayor que cero" << endl;

            }

            l.setId_libro(id_libro);
            l.setTitulo(titulo);
            l.setAutor(autor);
            l.setFecha_publicacion(fecha_publicacion);
            l.setGenero(genero);
            l.setPrecio(precio);
            l.setCantidad(cantidad);

            l.Editar();

        break;

        case 4:
            system("title Libreria: Eliminando");
            system("cls");


            while (true) {
                cout << "Ingrese la ID del libro: ";
                getline(cin, cad);
                stringstream mystream(cad);

                if (mystream >> id_libro and id_libro > 0) { break; }
                cout << "Error: ingrese un numero mayor a cero" << endl << endl;
            }
            
            l.setId_libro(id_libro);

            l.Borrar();

        break;


        case 5:

        return 0;

        }



    }


}
