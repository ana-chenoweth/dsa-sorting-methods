#include "../utils/Utileria.hpp"
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
//************************************************
void QuickSort(int v[], int n, int velocidadanimacion, int izq, int der, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);
    int i = izq, j = der, tmp;
    int p = v[(izq+der) / 2];

    while(i<= j)
    {
        while(v[i] < p) i++;
        while(v[j] > p) j--;
        if(i<= j)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            Imprimir(v,n, i, j, mayor);
            i++;
            j--;

            if(velocidadanimacion!=0){
                std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
            }
        }
    }
    if(izq < j) QuickSort(v, n, velocidadanimacion, izq, j, mayor);
    if(i < der) QuickSort(v, n, velocidadanimacion, i, der, mayor);

    CambiarCursor(ENCENDIDO, NORMAL);
}
//************************************************
void Merge(int v[], int n, int velocidadanimacion, int inicio, int mitad, int final, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);
    int i,j, k;

    int eleIzq = mitad - inicio + 1;
    int eleDer = final - mitad;

    int *VectorIzq = NULL;
    int *VectorDer = NULL;

    try{
    VectorIzq = Crear(n);
    VectorDer = Crear(n);

            Imprimir(v,n, inicio, final, mayor);
            if(velocidadanimacion!=0){
                std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
            }

    for(int i = 0; i< eleIzq; i++){
        VectorIzq[i] = v[inicio+i];
    }
    for(int j = 0; j< eleDer; j++){
        VectorDer[j] = v[mitad + 1 +j];
    }
    i = 0;
    j = 0;
    k = inicio;


    while(i < eleIzq && j < eleDer){
        if(VectorIzq[i] <= VectorDer[j]){
            v[k] = VectorIzq[i];
            i++;
        } else {
            v[k] = VectorDer[j];
            j++;
        }
        k++;
    }
    while(j < eleDer){
        v[k] = VectorDer[j];
        j++;
        k++;
    }
    while(i < eleIzq){
        v[k] = VectorIzq[i];
        i++;
        k++;
    }

    Destruir(VectorIzq);
    Destruir(VectorDer);


    }catch(const bad_alloc &){
    cout << "Error en la asignaci\242n de memoria" <<endl;
} catch(...){
    cout << "Ocurrio\242 un error inesperado" << endl;
}
}
//************************************************
void MergeSort(int v[], int n, int velocidadanimacion, int inicio, int final, int mayor)
{

    MoverCursor(0, mayor+4);
    cout << "Ordenando...                         " << endl;

    CambiarCursor(APAGADO, NORMAL);
    if(inicio < final){
        int mitad = inicio + (final -inicio)/2;
        MergeSort(v, n, velocidadanimacion, inicio, mitad, mayor);
        MergeSort(v, n, velocidadanimacion, mitad+1, final, mayor);
        Merge(v, n, velocidadanimacion, inicio, mitad, final, mayor);
    }

            Imprimir(v,n, inicio, final, mayor);
            if(velocidadanimacion!=0){
                std::this_thread::sleep_for(std::chrono::milliseconds(velocidadanimacion));
            }
}
//*************************************************