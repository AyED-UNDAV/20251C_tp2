#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <cstring> // strcat
using namespace std;

// Gustos disponibles
const char gustos[] = { 'D', 'C', 'V' };
const int CANT_GUSTOS = sizeof(gustos) / sizeof(gustos[0]);
const int MAX_REPORTE = 2001;
const int MAX_VENTA = 201;

// Función que genera un único helado (gustos + tamaño) y lo guarda en 'salida'
void generarVenta(char salida[MAX_VENTA]) {
    salida[0] = '\0'; // Inicializar cadena vacía

    int cantidadGustos = 1 + rand() % 5; // De 1 a 5 gustos

    for (int i = 0; i < cantidadGustos; i++) {
        char gusto = gustos[rand() % CANT_GUSTOS];

        int len = strlen(salida);
        salida[len] = gusto;
        salida[len + 1] = '\0';
    }

    // Agregar coma y tamaño (g o c)
    strcat(salida, ",");
    char tipo = (rand() % 2 == 0) ? 'g' : 'c';
    int len = strlen(salida);
    salida[len] = tipo;
    salida[len + 1] = '\0';
}

// ✅ Nueva función: genera todos los helados y los concatena en un solo char[]
void reporteHelados(char salidaFinal[MAX_REPORTE]) {
    salidaFinal[0] = '\0'; // Inicializar cadena vacía

    int cantidadRegistros = 3 + rand() % 8; // Entre 3 y 10 helados

    for (int i = 0; i < cantidadRegistros; i++) {
        char venta[MAX_VENTA];
        generarVenta(venta);

        strcat(salidaFinal, venta);

        // Si no es el último, agregar '|'
        if (i < cantidadRegistros - 1) {
            strcat(salidaFinal, "|");
        }
    }
}

