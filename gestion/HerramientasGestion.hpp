#ifndef HERRAMIENTASGESTION_HPP_INCLUDED
#define HERRAMIENTASGESTION_HPP_INCLUDED

#include <ctime>

/** VELOCIDAD */
enum Velocidad {
    RAPIDO,
    MEDIO,
    LENTO
};

void Capturar(int v[], int n);
void Azar(int a[], int n);
void AzarOCapturar(int a[], int n);
int Velocidad();

#endif // HERRAMIENTASGESTION_HPP_INCLUDED
