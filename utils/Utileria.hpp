#ifndef UTILERIA_HPP_INCLUDED
#define UTILERIA_HPP_INCLUDED

#include <limits>
#include <iostream>

// Límites definidos por compatibilidad
#define MAXTAMARR 100
#define MAXASTERISCOS 22

/** Estado cursor */
enum EstadoCursor {
    APAGADO,    /**< Cursor no visible */
    ENCENDIDO   /**< Cursor visible */
};

/** Modo cursor */
enum ModoCursor {
    MINI = 5,
    NORMAL = 40,
    SOLIDO = 80
};

// Funciones declaradas
int CapturarEntero(const char solicitud[]);
int CapturarElementos(const char solicitud[]);
int DimesionVector(const char NombreVector[]);
void MoverCursor(short x, short y);
void CambiarCursor(EstadoCursor estado, ModoCursor modo);

#endif // UTILERIA_HPP_INCLUDED
