#include "HerramientasVectores.hpp"
#include "Utileria.hpp"
#include <iostream>

using std::cout;

void Imprimir(const int a[], int n, int inicio, int fin, int mayor)
{
    for (int j = inicio; j <= fin; ++j) {
        for (int i = 0; i < mayor; ++i) {
            MoverCursor(j, i + 3);
            if (a[j] >= (mayor - i)) {
                cout << "║";
            } else {
                cout << " ";
            }
        }
    }
}

void Destruir(int*& v)
{
    delete[] v;
    v = nullptr;
}

int* Crear(int n)
{
    return new int[n];
}

int MayorArreglo(const int a[], int n)
{
    int mayor = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mayor) {
            mayor = a[i];
        }
    }
    return mayor;
}
