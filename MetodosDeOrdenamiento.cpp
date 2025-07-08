#include "Utileria.hpp"
#include "HerramientasVectores.hpp"
#include "MetodosDeOrdenamiento.hpp"
#include <iostream>
#include <thread>
#include <chrono>

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
//************************************************
void Seleccion(int v[], int n, int velocidadanimacion, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);

    int minimo;

    for(int i = 0; i < n - 1; i++){
        minimo = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[minimo]){
                minimo = j;
            }
        }
        if(minimo != i){
            Intercambiar(v[i], v[minimo]);
            Imprimir(v,n, i, minimo, mayor);
            if(velocidadanimacion!=0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
            }
        }
    }
    CambiarCursor(ENCENDIDO, NORMAL);
}
//************************************************
void Insercion(int v[], int n, int velocidadanimacion, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);
    int posAct, valorPos;

    for(int i = 1; i < n; i++){

        int valorPos = v[i];
        int posAct = i - 1;

        while(posAct >= 0 && v[posAct] > valorPos){
            v[posAct + 1] = v[posAct];
            posAct--;
            Imprimir(v,n, posAct+1, posAct+2, mayor);
            if(velocidadanimacion!=0){
                std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
            }
        }
        v[posAct + 1] = valorPos;
        Imprimir(v,n, posAct, posAct+1, mayor);
        if(velocidadanimacion!=0){
            std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
        }
    }
    CambiarCursor(ENCENDIDO, NORMAL);
}
//************************************************
void ShellSort(int v[], int n, int velocidadanimacion, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);
    int brecha = n / 2;
        while (brecha > 0) {
            bool recorrer = false;
            for (int i = brecha; i < n; i++) {
                int temp = v[i];
                int j = i;
                while (j >= brecha && v[j - brecha] > temp) {
                    v[j] = v[j - brecha];
                    j -= brecha;
                    recorrer = true;
                }
                v[j] = temp;
                if (recorrer) {
                Imprimir(v, n, j, i, mayor);
                if (velocidadanimacion != 0){
                    std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
                }
            }
            }
            brecha /= 2;
        }

    CambiarCursor(ENCENDIDO, NORMAL);
}