#include <iostream>
using namespace std;
#include "Persona.h"

bool salir = false;
void menu() {
        while (!salir){
            int opcion;
        cout << "|~~~~~ Menu de Clientes ~~~~~|" << endl;
        cout << "1. Agregar personas" << endl;
        cout << "2. Imprimir personas y sus datos" << endl;
        cout << "3. Salir" << endl;
        cout << "Digite la opcion que quiere realizar: ";
        try {
            std::cin >> opcion;
            std::cout << "\n";
        } catch (exception &e) {
            std::cout << "\nOpcion invalida intente, volviendo al menu..." << std::endl;
            cin.clear();
            cin.ignore();
            menu();
        }
        if (opcion == 1) {
            int cantidadPersonas;
            cout << "Digite la cantidad de personas que quiere crear: ";
            cin >> cantidadPersonas;
            crearPersonas(cantidadPersonas);
        }
        if (opcion == 2) {
            int cantidadPersonas;
            imprimirPersonas();
        }
        if (opcion == 3) {
            salir = true;
        }
    }
}