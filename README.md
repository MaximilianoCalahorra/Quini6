# Descripción del programa
Este programa consiste en un **simulador por consola del juego de azar Quini 6 desarrollado totalmente en C**.

Se corresponde con la operatoria del juego y además incluye:
- **Elección del cartón de juego de forma manual o automática**. En ambos casos, se valida constantemente que **ninguno de los 6 números del cartón esté repetido y que sean entre el 0 y 45 (ambos inclusive)**.
- **Premios**:
  - **El jugador solo puede aplicar a un tipo de premio por sorteo**, es decir, se llevará el de mayor valor que consiga según los números que acierte.
  - **El jugador participa en todas las instancias con el mismo cartón**.
  - El **primer sorteo** otorga un premio de **$5.000.000 a quien acierte los 6 números**, uno de **$200.000 a quien acierte 5 de los 6 números** y uno de **$500 a quien acierte 4 de los 6 números**. 
  - El **segundo sorteo** otorga un premio de **$2.000.000 a quien acierte los 6 números**.
  - El **tercer sorteo** otorga un premio de **$1.000.000 a quien acierte los 6 números**, uno de **$100.000 a quien acierte 5 de los 6 números** y uno de **$2.000 a quien acierte 4 de los 6 números**.
  - **Por último, se juntan los números de los 3 sorteos y quien tenga aunque sea 6 de esos 18 números se lleva $1.000**.
- Luego de cada sorteo se le muestra al jugador el cartón ganador, el suyo, la cantidad de aciertos y el premio obtenido.
- Al final de todos los sorteos, se le informa al jugador cuál fue su premio total conseguido.  
- El juego se repite indefinidamente mientras el jugador no haya ganado el pozo mayor en el primer sorteo, es decir, mientras el cartón seleccionado no sea exactamente igual al ganador.
  Una vez que esto sucede, se le informa al jugador el total ganado y la cantidad de sorteos completos que fueron necesarios para lograrlo.

*Gracias por interesarte en visitar este repositorio y leer acerca de él*.

¡Saludos!

Maximiliano Calahorra.
