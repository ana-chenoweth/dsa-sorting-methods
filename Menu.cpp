#include "Utileria.hpp"
#include "Menu.hpp"

using std::cout;
using std::endl;

int Menu()
{
    int opcion;
    cout << SALIR      << ") Salir del programa" << endl;
    cout << BURBUJA    << ") Ordenar por Burbuja" << endl;
    cout << SELECCION  << ") Ordenar por Selección" << endl;
    cout << INSERCION  << ") Ordenar por Inserción" << endl;
    cout << SHELLSORT  << ") Ordenar Inserción con intervalos decrecientes (Shell Sort)" << endl;
    cout << QUICKSORT  << ") Rápido (Quick Sort)" << endl;
    cout << MERGESORT  << ") Mezcla (Merge Sort)" << endl;

    do {
        opcion = CapturarEntero("Elija una opción: ");
        if (opcion < SALIR || opcion > MERGESORT)
            cout << "Error: no existe esa opción" << endl;
    } while (opcion < SALIR || opcion > MERGESORT);

    return opcion;
}
