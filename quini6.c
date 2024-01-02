#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quini6.h"

int pedirOpcion()
{
    int op;
    do
    {
        printf("\nBienvenido al sistema de compra de boletas del Quini 6!\n");
        printf("\nIngrese una de las siguientes opciones:\n");
        printf("#1: comprar boleta e ingresar los 6 numeros manualmente\n");
        printf("#2: comprar boleta y elegir los 6 numeros aleatoriamente\n");
        printf("Su opcion: #");
        scanf("%d", &op);
    }
    while((op <1) || (op > 2));
    return op;
}

int generarAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void cargarBoleta(int opElegida, int bo[], int cNumeros)
{
    for (int i = 0; i < cNumeros; i++)
    {
        if (opElegida == 1)
        {
            int numIngresado;
            printf("Ingrese un numero para la posicion #%d de la boleta: ", i + 1);
            scanf("%d", &numIngresado);
            if ((numIngresado < 0) || (numIngresado > 45))
            {
                printf("Ingresaste el %d y los numeros validos son enteros entre 0 y 45, ingrese nuevamente\n", numIngresado);
                i--;
            }
            else
            {
                bo[i] = numIngresado;
            }
            for (int j = 0; j < i; j++)
            {
                if (bo[j] == bo[i])
                {
                    printf("Se repite el numero %d, ingrese nuevamente\n", bo[j]);
                    i--; ///Se repite uno de los números. Decrementamos para generar otro.
                }
            }
        }
        else
        {
            bo[i] = generarAleatorio(0, 45);
            for (int j = 0; j < i; j++)
            {
                if (bo[j] == bo[i])
                {
                    i--; ///Se repite uno de los números. Decrementamos para generar otro.
                }
            }
        }
    }
}

void mostrarBoleta(int bo[], int cNumeros)
{
    printf("\nSu boleta:\n");
    for (int i = 0; i < cNumeros; i++)
    {
        printf(" |%d| ", bo[i]);
    }
    printf("\n");
}

void cargarJugadas(int ju[][6], int cJugadas, int cNumeros)
{
    for (int i = 0; i < cJugadas; i++)
    {
        for (int j = 0; j < cNumeros; j++)
        {
            ju[i][j] = generarAleatorio(0, 45);
            for (int k = 0; k < j; k++)
            {
                if (ju[i][k] == ju[i][j])
                {
                    j--;
                }
            }
        }
    }
}

void mostrarJugada(int ju[][6], int cJugadas, int cNumeros, int nJugada)
{
    printf("\nJugada %d:\n", nJugada + 1);
    for (int j = 0; j < cNumeros; j++)
    {
        printf(" |%d| ", ju[nJugada][j]);
    }
    printf("\n");
}

void mostrarJugadas(int ju[][6], int cJugadas, int cNumeros)
{
    for (int i = 0; i < cJugadas; i++)
    {
        mostrarJugada(ju, cJugadas, cNumeros, i);
    }
}

int contarAciertosDeJugada(int ju[][6], int cJugadas, int cNumeros, int bo[], int nJugada)
{
    int aciertos = 0;
    for (int i = 0; i < cNumeros; i++)
    {
        if(bo[i] == ju[nJugada][i])
        {
            aciertos++;
        }
    }
    return aciertos;
}

int sumarAciertosDeJugadas(int aJugada1, int aJugada2, int aJugada3)
{
    return aJugada1 + aJugada2 + aJugada3;
}

int asignarPremios(int cAciertos, int nJugada)
{
    int premiosJugada = 0;
    switch(nJugada)
    {
        case 0:
        {
            if (cAciertos == 6)
            {
                printf("\nFelicitaciones! Acertaste los 6 numeros y ganaste $5.000.000\n");
                premiosJugada = 5000000;
            }
            else if (cAciertos == 5)
            {
                printf("\nFelicitaciones! Acertaste 5 de 6 numeros y ganaste $2000.000\n");
                premiosJugada = 200000;
            }
            else if (cAciertos == 4)
            {
                printf("\nFelicitaciones! Acertaste 4 de 6 numeros y ganaste $500\n");
                premiosJugada = 500;
            }
            else
            {
                printf("\nNo ganaste ningun premio en la jugada %d porque acertaste %d de 6 numeros\n", nJugada + 1, cAciertos);
            }
        }
        break;
        case 1:
        {
            if (cAciertos == 6)
            {
                printf("\nFelicitaciones! Acertaste los 6 numeros y ganaste $2.000.000\n");
                premiosJugada = 2000000;
            }
            else
            {
                printf("\nNo ganaste ningun premio en la jugada %d porque acertaste %d de 6 numeros\n", nJugada + 1, cAciertos);
            }
        }
        break;
        case 2:
        {
            if (cAciertos == 6)
            {
                printf("\nFelicitaciones! Acertaste los 6 numeros y ganaste $1.000.000\n");
                premiosJugada = 1000000;
            }
            else if (cAciertos == 5)
            {
                printf("\nFelicitaciones! Acertaste 5 de 6 numeros y ganaste $100.000\n");
                premiosJugada = 100000;
            }
            else if (cAciertos == 4)
            {
                printf("\nFelicitaciones! Acertaste 4 de 6 numeros y ganaste $1000\n");
                premiosJugada = 1000;
            }
            else
            {
                printf("\nNo ganaste ningun premio en la jugada %d porque acertaste %d de 6 numeros\n", nJugada + 1, cAciertos);
            }
        }
        break;
        case 3:
        {
            if (cAciertos >= 6)
            {
                printf("\nFelicitaciones! Acertaste %d de 18 numeros y ganaste $1000\n", cAciertos);
                premiosJugada = 1000;
            }
            else
            {
                printf("\nNo ganaste ningun premio en el combinado porque acertaste %d de 18 numeros\n", cAciertos);
            }
        }
    }
    return premiosJugada;
}

void entregarPremios(int pJugada1, int pJugada2, int pJugada3, int pJugada4)
{
    int premiosTotales = pJugada1 + pJugada2 + pJugada3 + pJugada4;
    if (premiosTotales > 0)
    {
        printf("\nFelicitaciones! En total ganaste $%d\n", premiosTotales);
    }
    else
    {
        printf("\nNo te rindas! Esta vez no ganaste, pero quizas la proxima\n");
    }
}

void finDelMenu(int opElegida, int prJugada1, int prJugada2, int prJugada3, int prJugada4, int cSorteos)
{
    if ((opElegida == 1) || (opElegida == 2))
    {
        printf("\nGanaste el gran premio!!!\n");
        entregarPremios(prJugada1, prJugada2, prJugada3, prJugada4);
        printf("\nSe necesitaron %d jugada/s para lograrlo\n", cSorteos);
        printf("\nGracias por usar el programa\n");
    }
}
