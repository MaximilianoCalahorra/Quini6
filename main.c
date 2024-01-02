#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quini6.h"

int main()
{
    srand(time(0));
    int cantJugadas = 3;
    int cantNumeros = 6;
    int jug[cantJugadas][cantNumeros];
    int bol[cantNumeros];
    int aciertosJugada1;
    int aciertosJugada2;
    int aciertosJugada3;
    int premiosJugada1;
    int premiosJugada2;
    int premiosJugada3;
    int premiosJugada4;
    int cantidadSorteos = 0;
    int opcElegida;
    do
    {
        opcElegida = pedirOpcion();
        cargarBoleta(opcElegida, bol, cantNumeros);
        cargarJugadas(jug, cantJugadas, cantNumeros);
        cantidadSorteos++;
        aciertosJugada1 = contarAciertosDeJugada(jug, cantJugadas, cantNumeros, bol, 0);
        mostrarJugada(jug, cantJugadas, cantNumeros, 0);
        mostrarBoleta(bol, cantNumeros);
        premiosJugada1 = asignarPremios(aciertosJugada1, 0);
        aciertosJugada2 = contarAciertosDeJugada(jug, cantJugadas, cantNumeros, bol, 1);
        mostrarJugada(jug, cantJugadas, cantNumeros, 1);
        mostrarBoleta(bol, cantNumeros);
        premiosJugada2 = asignarPremios(aciertosJugada2, 1);
        aciertosJugada3 = contarAciertosDeJugada(jug, cantJugadas, cantNumeros, bol, 2);
        mostrarJugada(jug, cantJugadas, cantNumeros, 2);
        mostrarBoleta(bol, cantNumeros);
        premiosJugada3 = asignarPremios(aciertosJugada3, 2);
        int aciertosTotales = sumarAciertosDeJugadas(aciertosJugada1, aciertosJugada2, aciertosJugada3);
        mostrarJugadas(jug, cantJugadas, cantNumeros);
        mostrarBoleta(bol, cantNumeros);
        premiosJugada4 = asignarPremios(aciertosTotales, 3);
        entregarPremios(premiosJugada1, premiosJugada2, premiosJugada3, premiosJugada4);
    }
    while (aciertosJugada1 < 6);
    finDelMenu(opcElegida, premiosJugada1, premiosJugada2, premiosJugada3, premiosJugada4, cantidadSorteos);
    return 0;
}
