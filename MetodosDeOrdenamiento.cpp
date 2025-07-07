#include "Utileria.hpp"
#include "HerramientasVectores.hpp"
#include "MetodosDeOrdenamiento.hpp"
#include <iostream>
#include <thread>       // para sleep
#include <chrono>       // para sleep

using namespace std;

//*************************************************
template<typename Tipo>
void Intercambiar(Tipo& a, Tipo& b)
{
    Tipo aux = a;
    a = b;
    b = aux;
}

//************************************************
void Burbuja(int v[], int n, int velocidadanimacion, int mayor)
{
    MoverCursor(0, mayor + 4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);

    bool estaOrdenado;
    for (int j = n - 1; j > 0; --j) {
        estaOrdenado = true;
        for (int i = 0; i < j; i++) {
            if (v[i] > v[i + 1]) {
                Intercambiar(v[i], v[i + 1]);
                Imprimir(v, n, i, i + 1, mayor);
                if (velocidadanimacion != 0) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
                }
                estaOrdenado = false;
            }
        }
        if (estaOrdenado) break;
    }

    CambiarCursor(ENCENDIDO, NORMAL);
}
