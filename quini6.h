#ifndef QUINI6_H_INCLUDED
#define QUINI6_H_INCLUDED

int pedirOpcion();
int generarAleatorio(int minimo, int maximo);
void cargarBoleta(int opcionElegida, int boleta[], int cantidadNumeros);
void mostrarBoleta(int boleta[], int cantidadNumeros);
void cargarJugadas(int jugadas[][6], int cantidadJugadas, int cantidadNumeros);
void mostrarJugada(int jugadas[][6], int cantidadJugadas, int cantidadNumeros, int numeroJugada);
void mostrarJugadas(int jugadas[][6], int cantidadJugadas, int cantidadNumeros);
int contarAciertosDeJugada(int jugadas[][6], int cantidadJugadas, int cantidadNumeros, int boleta[], int numeroJugada);
int sumarAciertosDeJugadas(int aciertosJugada1, int aciertosJugada2, int aciertosJugada3);
int asignarPremios(int cantidadAciertos, int numeroJugada);
void entregarPremios(int premiosJugada1, int premiosJugada2, int premiosJugada3, int premiosJugada4);
void finDelMenu(int opcElegida, int premiosJugada1, int premiosJugada2, int premiosJugada3, int premiosJugada4, int cantidadSorteos);

#endif // QUINI6_H_INCLUDED
