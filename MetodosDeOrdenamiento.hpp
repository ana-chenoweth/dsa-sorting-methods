#ifndef METODOSDEORDENAMIENTO_HPP_INCLUDED
#define METODOSDEORDENAMIENTO_HPP_INCLUDED

template<typename Tipo>
void Intercambiar(Tipo& a, Tipo& b);

void Burbuja(int v[], int n, int velocidadanimacion, int mayor);
void Seleccion(int v[], int n, int velocidadanimacion, int mayor);
void Insercion(int v[], int n, int velocidadanimacion, int mayor);

#endif // METODOSDEORDENAMIENTO_HPP_INCLUDED
