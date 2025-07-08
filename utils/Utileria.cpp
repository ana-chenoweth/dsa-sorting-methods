#include "Utileria.hpp"
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;

int CapturarEntero(const char solicitud[])
{
    int x;
    cout << solicitud;
    cin >> x;
    while (cin.fail() || x < 0) {
        cout << "Error: valor no válido. ";
        if (x < 0) {
            cout << "Debe ser positivo. ";
        } else {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        cout << solicitud;
        cin >> x;
    }
    return x;
}

int CapturarElementos(const char solicitud[])
{
    int x;
    cout << solicitud;
    cin >> x;
    while (cin.fail() || x <= 0 || x > MAXASTERISCOS) {
        cout << "Error: valor no válido. ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        } else if (x <= 0) {
            cout << "Debe ser positivo. ";
        } else {
            cout << "Supera el máximo de asteriscos (" << MAXASTERISCOS << "). ";
        }
        cout << solicitud;
        cin >> x;
    }
    return x;
}

int DimesionVector(const char NombreVector[])
{
    cout << endl << "CAPTURA DE DATOS" << endl << endl;
    int dim;
    do {
        cout << "Rango[10, 100]" << endl;
        dim = CapturarEntero("¿Cuántos valores desea capturar?: ");
    } while (dim < 10 || dim > 100);
    return dim;
}

void MoverCursor(short x, short y)
{
    // ANSI escape codes: \033[y;xH
    cout << "\033[" << y << ";" << x << "H";
}

void CambiarCursor(EstadoCursor estado, ModoCursor modo)
{
    if (estado == APAGADO)
        cout << "\033[?25l";  // ocultar
    else
        cout << "\033[?25h";  // mostrar

}
