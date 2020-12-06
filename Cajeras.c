 /*
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2012
VERSIÓN: 1.3

DESCRIPCIÓN: Ejemplo de atención de dos cola de clientes, la simulación
de tiempo se reliza con la función Sleep(Solo funciona en Windows), cada X
tiempo llega un cliente y escoje pseudoaleatoriamente una cola y el tiempo 
de atención es Y.

OBSERVACIONES: Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán 
tener un campo int n;

COMPILACIÓN: 	gcc -o Cajeras Cajeras.c TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Cajeras Cajeras.c TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: Cajeras.exe (En Windows)
*/

//LIBRERAS
#include <time.h>
#include <stdio.h>
#include <windows.h>				//Funciona unicamente en Windows para usar la función Sleep()
//#include "TADCola/TADColaEst.h" 	//Si se usa la implemtentación dinámica (TADColaDin.c)
#include "TADColaDin.h" 	//Si se usa la implemtentación estática (TADColaEst.c|TADColaEstCirc.c)

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE	100			//Tiempo base en ms
#define TIEMPO_CLIENTE	2 		//Tiempo base en ms * 1
#define TIEMPO_ATENCION	3		//Tiempo base en ms * 3

int main(void)
{
	unsigned int tiempo = 0;
	unsigned int cliente = 0;
	unsigned int LlegadaCliente = 0;
	int i,fila,NumCajas,atencion[10];
	elemento e;
	//Inicializar la función rand
	srand(time(NULL));
	printf("Walmart\n");
	printf("Cajas abiertas: \t");
	scanf("%d",&NumCajas);
	//Crear colas
	cola cajera[NumCajas];
	
	//Inicializar ambas colas
	for(int z=0;z<NumCajas;z++)
	{ Initialize(&cajera[z]);}
	
	//Ciclo infinito
	if(NumCajas>0 && NumCajas<11)
	{
		for(i=0;i<NumCajas;i++)
		{	
			printf("Tiempo de atencion de cajera %d\t",i+1);
			scanf("%d",&atencion[i]);
			if(atencion[i] % 10!=0)
			{
				printf("El tiempo de atencion no es multiplo de 10ms\t");
				exit(1);
			}
		}
		printf("Tiempo de llegada de cada cliente\t");
		scanf("%d",&LlegadaCliente);
		if(LlegadaCliente % 10!=0)
		{
			printf("El tiempo de llegada no es multiplo de 10ms\t");
			exit(1);
		}
	}
	
	
	
		Sleep(TIEMPO_BASE);		//Esperar el tiempo base
		tiempo++;				//Incrementar el contador de tiempo
		int c=0;
		//Si el tiempo es multiplo del tiempo de atencion
		if (tiempo % TIEMPO_BASE == 0)
		{
			for(int x=0;x<NumCajas;x++)
			{
				//Cajera 0
				if (!Empty(&cajera[x]))
				{
					Sleep(fila);
					e = Dequeue(&cajera[x]);
					printf("\n\n\nAtendi a: %d en caja %d", e.n,x);
				}
				else
				{
					printf("\n\n\nNo hay alguien por atender en caja ",x);
				}
			}
		}
		//Si el tiempo es multiplo del de llegada de los clientes
		if (LlegadaCliente % TIEMPO_BASE == 0)
		{
			cliente++;				//Incrementar el numero de clientes
			e.n = cliente;			//Dar el numero que identifica al cliente
			fila=rand()%5;			//Escoger la fila para formarse aleatoriamente					
			Queue(&cajera[fila], e);//Formarse en la fila seleccionada
			printf("\n\n\nLlego el cliente: %d a la cola de la caja %d", e.n,fila);
		}
		
		//Mostrar los clientes en cada cola
		printf("\n\n%d clientes en cola 0: [",Size(&cajera[0]));
		for (i=1;i<=Size(&cajera[0]);i++)
		{
			e=Element(&cajera[0],i);
			printf("%d\t", e.n);
		}
		printf("]");
		c++;
		
	return 0;
}
