#include "Gestiones.hpp"
#include "Utileria.hpp"
#include "HerramientasGestion.hpp"
#include "HerramientasVectores.hpp"
#include "MetodosDeOrdenamiento.hpp"
#include "Menu.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
   int opcion;
    do {
        system("clear");
        cout << "Programa que ordena listas de datos..." << endl;
        cout << "\nOpciones: " << endl;
        opcion = Menu();

        switch (opcion) {
            case SALIR:
                cout << "Gracias por utilizar este programa" << endl;
                break;
            case BURBUJA:
                system("clear");
                cout << "Burbuja..." << endl;
                GestionBurbuja();
                break;
            case SELECCION:
                system("clear");
                cout << "Selección..." << endl;
                GestionSeleccion();
                break;
            case INSERCION:
                system("clear");
                cout << "Inserción..." << endl;
                GestionInsercion();
                break;
            case SHELLSORT:
                system("clear");
                cout << "Inserción con intervalos decrecientes (Shell Sort) ..." << endl;

                break;
            case QUICKSORT:
                system("clear");
                cout << "Rápido (Quick Sort) ..." << endl;

                break;
            case MERGESORT:
                system("clear");
                cout << "Mezcla (Merge Sort)  ..." << endl;

                break;
        }

        cout << "\n\nPresiona ENTER para continuar...";
        cin.ignore();  // limpiar buffer si es necesario
        cin.get();     // espera ENTER

    } while (opcion != SALIR);

    return 0;
}