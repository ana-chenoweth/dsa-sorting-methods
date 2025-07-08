#include "HerramientasGestion.hpp"
#include "HerramientasVectores.hpp"
#include "Gestiones.hpp"
#include "MetodosDeOrdenamiento.hpp"
#include "Utileria.hpp"

#include <iostream>
#include <cstdlib>  // para system("clear")

using namespace std;

void GestionBurbuja()
{
    int* v = nullptr;
    int dim;

    dim = DimesionVector("Arreglo: ");

    try {
        v = Crear(dim);
        AzarOCapturar(v, dim);

        int velocidadanimacion = Velocidad();
        int mayor = MayorArreglo(v, dim);

        system("clear");
        cout << " >> ORDENAMIENTO BURBUJA" << endl;

        Imprimir(v, dim, 0, dim - 1, mayor);

        cout << endl << endl;
        cout << "Proceso de ordenamiento en breve..." << endl;

        Burbuja(v, dim, velocidadanimacion, mayor);

        cout << endl << endl << "Fin del ordenamiento " << endl;

        Destruir(v);
    }
    catch (const bad_alloc&) {
        cout << "Error en la asignación de memoria" << endl;
    }
    catch (...) {
        cout << "Ocurrió un error inesperado" << endl;
    }
}
//*************************************************
void GestionSeleccion()
{
    int *v = NULL;
    int dim;

    dim = DimesionVector("Arreglo: ");

    try{
    v = Crear(dim);

    AzarOCapturar(v, dim);

    int velocidadanimacion = Velocidad();
    int mayor = MayorArreglo(v, dim);

    system("cls");
    cout << " >> ORDENAMIENTO SELECCION";
    Imprimir(v,dim, 0, dim-1, mayor);
    cout << endl << endl;
    cout << "Proceso de ordenamiento en breve..." << endl;

    Seleccion(v, dim, velocidadanimacion, mayor);

    cout << endl << endl << "Fin del ordenamiento " << endl;
    Destruir(v);

    }catch(const bad_alloc &){
    cout << "Error en la asignaci\242n de memoria" <<endl;
} catch(...){
    cout << "Ocurrio\242 un error inesperado" << endl;
}
}
//*************************************************
void GestionInsercion()
{
    int *v = NULL;
    int dim;

    dim = DimesionVector("Arreglo: ");

    try{
    v = Crear(dim);

    AzarOCapturar(v, dim);

    int velocidadanimacion = Velocidad();
    int mayor = MayorArreglo(v, dim);

    system("cls");
    cout << " >> ORDENAMIENTO INSERCION";
    Imprimir(v,dim, 0, dim-1, mayor);
    cout << endl << endl;
    cout << "Proceso de ordenamiento en breve..." << endl;


    Insercion(v, dim, velocidadanimacion, mayor);

    cout << endl << endl << "Fin del ordenamiento " << endl;
    Destruir(v);

    }catch(const bad_alloc &){
    cout << "Error en la asignaci\242n de memoria" <<endl;
} catch(...){
    cout << "Ocurrio\242 un error inesperado" << endl;
}
}