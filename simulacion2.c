/*
AUTORES: Lechuga Canales Hector Jair y Manrique Abad Josue Rafael
VERSIÓN: 1.1

DESCRIPCIÓN: 

OBSERVACIONES: Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán 
tener un campo int n;

COMPILACIÓN: 	gcc -o Procesos Procesos.c TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Procesos Procesos.c TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: Procesos.exe (En Windows)
*/
//LIBRERAS
#include <stdio.h>
#include <string.h>
#include "TADColaEst.h" 

elemento Datos_proceso(int n);

int main (void)
{
	cola listos, finalizados;
	Initialize(&listos);
	Initialize(&finalizados);
	int procesos, tiempo, i, j, n=1;
	elemento e;
	printf("Procesos a ingresar: ");
	scanf("%d", &procesos);
	while(n<=procesos)
	{
		e=Datos_proceso(n);
		Queue(&listos, e);
		n++;
	}
	
	printf("%d", Size(&listos));
	return 0;
}
elemento Datos_proceso(int n)
{
	elemento e;
	int t,i;
	char nombre[45], actividad[200], ID[45];

	printf("\nNombre del proceso:");
	scanf("%s[^\n]", &nombre);
	fflush(stdin);

	printf("ID:");
	scanf("%s",&ID);

	printf("Actividad:");
	scanf("%s[^\n]", &actividad);
	fflush(stdin);

	printf("Tiempo de ejecucion:");
	scanf("%d",&t);	

	return e;
}
