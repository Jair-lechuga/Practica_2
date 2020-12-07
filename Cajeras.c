/*
AUTORES: Lechuga Canales Hector Jair y Manrique Abad Josue Rafael
VERSIÓN: 1.5

DESCRIPCIÓN: Simulacion de la atencion a clientes de un supermercado
Se abrira un cierto numero de cajas y cada cierto toempo un cliente llegara, 
cada caja tendra un tiempo determinado para atender, el programa podra finalizar 
si ya se atendio como minimo al cliente 100 y no hay mas clientes formados en las cajas.

OBSERVACIONES: Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán 
tener un campo int n;

COMPILACIÓN: 	gcc -o Super Super.c TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Super Super.c TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: Super.exe (En Windows)
*/
//LIBRERAS
#include <time.h>
#include <stdio.h>
#include <windows.h>			
//#include "TADCola/TADColaEst.h" 
#include "TADColaDin.h" 
#define TIEMPO_BASE	100	 //Tiempo base en ms

int main(void)
{
	unsigned int tiempo = 0;
	unsigned int cliente = 0;
	unsigned int LlegadaCliente = 0;
	int i=0,fila,NumCajas,atencion[10];
	int meta=0;
	elemento e;
	//Inicializar la función rand
	srand(time(NULL));
	printf("Walmart\n");
	printf("Cajas abiertas:");
	scanf("%d",&NumCajas);
	//Crear colas
	cola cajera[NumCajas];
	int att[NumCajas];
	//Inicializar ambas colas
	for(i=0;i<NumCajas;i++)
	{ Initialize(&cajera[i]);}
	
	if(NumCajas>0 && NumCajas<11)
	{
		for(i=0;i<NumCajas;i++)
		{	
			printf("Tiempo de atencion de cajera %d:",i+1);
			scanf("%d",&atencion[i]);
			if(atencion[i] % 10!=0)
			{
				printf("El tiempo de atencion no es multiplo de 10ms\t");
				exit(1);
			}
		}
		printf("Tiempo de llegada de cada cliente: ");
		scanf("%d",&LlegadaCliente);
		if(LlegadaCliente % 10!=0)
		{
			printf("El tiempo de llegada no es multiplo de 10ms\t");
			exit(1);
		}
	}
	//Ciclo infinito
	while(1)
	{
		Sleep(TIEMPO_BASE);		
		tiempo++;				
		int c=0;
		//Si el tiempo es multiplo del tiempo de atencion
		for(i=0;i<NumCajas;i++)
		{
				if (!Empty(&cajera[i]) && tiempo%atencion[i] == 0)
				{
					Sleep(TIEMPO_BASE);
					e = Dequeue(&cajera[i]);
					printf("\n\n\nAtendi a: %d en caja %d", e.n,i+1);
				}
		}
		//Si el tiempo es multiplo del de llegada de los clientes
		if (tiempo % LlegadaCliente == 0)
		{
			meta=0;
			cliente++;				//Incrementar el numero de clientes
			e.n = cliente;			//Dar el numero que identifica al cliente
			fila=rand()%NumCajas;	//Escoger la fila para formarse aleatoriamente					
			Queue(&cajera[fila], e);//Formarse en la fila seleccionada
			printf("\n\n\nLlego el cliente: %d a la cola de la caja %d", e.n,fila+1);
			meta+=e.n;
		}
		if(meta>=100)
		{
			int ban=0;
			for(i=0;i<NumCajas;i++)
			{
				if(Empty(&cajera[i]))
				{
					ban++;
				}
			}
			if(ban==NumCajas)
			{
				printf("\n\n\nNo hay nadie mas en la cola,la tienda cerro");
				exit(1);
			}
		}
		//Mostrar los clientes en cada cola
		/*printf("\n\n%d clientes en cola 0: [",Size(&cajera[0]));
		for (i=1;i<=Size(&cajera[0]);i++)
		{
			e=Element(&cajera[0],i);
			printf("%d\t", e.n);
		}
		printf("]");*/
		c++;
	}
	return 0;
}
