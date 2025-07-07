#include "Utileria.hpp"
#include "HerramientasGestion.hpp"
#include <iostream>
#include <cstdlib>  // para rand, srand
#include <ctime>    // para time

using std::cout;
using std::endl;

void Capturar(int a[], int n)
{
    cout << endl << "Los valores que ingrese deben ser positivos y no más de " << MAXASTERISCOS << endl;

    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1;
        a[i] = CapturarElementos(":  ");
    }
}

void Azar(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = 1 + rand() % (MAXASTERISCOS);
    }
}

int Velocidad()
{
    cout << endl << "Velocidades de animación:" << endl;
    cout << "\t 0) Rápida" << endl;
    cout << "\t 1) Media" << endl;
    cout << "\t 2) Lenta" << endl << endl;

    int opcion;
    do {
        opcion = CapturarEntero("¿Qué velocidad quiere la animación? ");
    } while (opcion != RAPIDO && opcion != MEDIO && opcion != LENTO);

    switch (opcion) {
        case RAPIDO: return 0;
        case MEDIO:  return 40;
        case LENTO:  return 80;
        default:     return 40;  // Valor seguro por defecto
    }
}

void AzarOCapturar(int a[], int n)
{
    int opcion;
    cout << endl << "Método de llenado: " << endl;
    cout << "\t 0. Al azar" << endl;
    cout << "\t 1. Captura Manual" << endl << endl;

    do {
        opcion = CapturarEntero("¿Cómo desea obtener los datos? ");
    } while (opcion != 1 && opcion != 0);

    if (opcion == 1) {
        Capturar(a, n);
    } else {
        Azar(a, n);
    }
}
