/*
Se valorará el uso de estructuras, enumerados, uniones, ficheros y una correcta gestión de la memoria. 
No es necesario que en los enunciados se escriba explícitamente que se deba usar memoria dinámica u algún tipo de estructura, el alumno debe saber en qué
contexto debe usarse cada elemento.
En caso de necesitar un fichero en concreto, el alumno deberá crearlo en su máquina con los datos correspondientes.
En el caso de que se requiera usar alguna función NO está permitido modificar su cabecera.
Las salidas por consola de los ejercicios deben coincidir exactamente con los ejemplos mostrados en el enunciado. 
Esto incluye el formato, el orden y los textos indicados.
El alumno debe realizar los dos programas que a continuación se detallan. El primero tendrá una calificación de 4 sobre 10 y el segundo de 6 sobre 10


La empresa SmartCity dispone de una red de sensores urbanos encargados de monitorizar distintos parámetros ambientales de la ciudad. 
Cada sensor genera eventos que son almacenados en un fichero de texto para su posterior análisis.
Cada línea del fichero contiene información sobre un evento generado por un sensor con el siguiente formato:
	TIPO_SENSOR;VALOR;ESTADO

Donde:
	• TIPO_SENSOR puede tomar uno de los siguientes valores:
		o TEMP
		o HUM
		o AIR
	
	• VALOR es un número entero positivo correspondiente a la medición realizada por el sensor.
	• ESTADO indica si la medición es válida:
		o OK
		o ERROR

Ejemplo de fichero de entrada:
TEMP;24;OK
HUM;80;OK
AIR;45;ERROR
TEMP;30;OK
HUM;70;OK

1) Realiza un programa que lea todos los eventos del fichero de entrada y los almacene en memoria. 
2) Posteriormente, el programa deberá generar un fichero de salida con un resumen de los sensores válidos (OK) indicando, para cada tipo de sensor, el número de
muestras válidas y el valor máximo registrado.
3) Además, el programa deberá mostrar por pantalla todos los sensores cuyo estado sea ERROR.

El programa deberá ejecutarse con el siguiente formato: ./analizaSensores.exe <fichero_entrada.txt> <fichero_salida.txt>
Ejemplo de salida por pantalla:
Sensores con error:
AIR -> 45
Ejemplo de fichero de salida:
TEMP;2;30
HUM;2;80
AIR;0;0

Es obligatorio implementar las siguientes funciones:
- Lee dinámicamente una línea desde un fichero: char *leerLineaDinamicaFile(FILE *fd)
- Recibe una cadena de texto con el tipo de sensor y devuelve el valor correspondiente: tipoSensor_t obtenerTipoSensor(char *cadena)
- Recibe una cadena de texto con el estado del sensor y devuelve el valor correspondiente: estadoSensor_t obtenerEstadoSensor(char *cadena)
- Recibe una línea del fichero y devuelve un eventoSensor_t con los datos correspondientes al evento: eventoSensor_t parseaEvento(char *linea)
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){
	printf("Hola");
	return 0;
}
