/*
Instituto Politecnico Nacional
Escuela Superior de Cómputo
Analisis de algoritmos
Grupo: 3CV2
Alumnos: Garcia Tello Axel
		 Rodríguez Acosta Alan
Profesor: Benjamin Luna Benoso
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
mochila completa
Fecha: 30 de mayo de 2020
*/
#include "mochila.h"


PRODUCTOS crearProductos(int numeroDeProductos,int peso)
{
	PRODUCTOS auxiliar=(PRODUCTOS)malloc(numeroDeProductos*sizeof(PRODUCTO));
	int i;

	srand(time(NULL));

	for (i = 1; i <= numeroDeProductos; ++i)
	{
		auxiliar[i].peso=(rand()%15)+2;
		auxiliar[i].beneficio=(rand()%200)+30;
	}
	return auxiliar;
}

MOCHILAF crearMochilas(int numeroDeMochilas)
{
	MOCHILAF auxiliar=(MOCHILAF)malloc(numeroDeMochilas*sizeof(MOCHILA));
	return auxiliar;
}

MOCHILAF crearMochila(int numeroDeMochilas)
{
	MOCHILAF auxiliar=(MOCHILAF)malloc(sizeof(MOCHILA));
	auxiliar->conjuntoSolucion=(PRODUCTOS)malloc(numeroDeMochilas*sizeof(PRODUCTO));
	auxiliar->cantidad=0;
	//auxiliar->cantidad=(int *)calloc(numeroDeMochilas,sizeof(int));
	return auxiliar;
}

void asignarPesosMochila(MOCHILAF mochilas,int numeroDeMochilas)
{
	int i;

	srand(time(NULL));

	for (i = 0; i < numeroDeMochilas; ++i)
	{
		mochilas[i].peso=(rand()%2000)+500;
	}
}

void mostrarMochila(MOCHILAF mochila,int opcion)
{
	int i,beneficio=0,peso=0;
	FILE *arch=fopen("beneficio.txt","a");
	FILE *arch1=fopen("peso.txt","a");
	FILE *arch2=fopen("razon.txt","a");
	for (i = 0; i < mochila->cantidad; ++i)
	{
		peso+=mochila->conjuntoSolucion[i].peso;
		beneficio+=mochila->conjuntoSolucion[i].beneficio;
	}
	if (opcion==1)
	{
		fprintf(arch, "%d\n",beneficio);
		printf("Seleccion por beneficio\nBeneficio total:%d\nPeso Mochila:%d\nPeso acumulado del conjunto:%d\n",beneficio,mochila->peso,peso);
	}
	else if (opcion==2)
	{
		fprintf(arch1, "%d\n",beneficio);
		printf("Seleccion por peso\nBeneficio total:%d\nPeso Mochila:%d\nPeso acumulado del conjunto:%d\n",beneficio,mochila->peso,peso);
	}
	else if (opcion==3)
	{
		fprintf(arch2, "%d\n",beneficio);
		printf("Seleccion por razon\nBeneficio total:%d\nPeso Mochila:%d\nPeso acumulado del conjunto:%d\n",beneficio,mochila->peso,peso);
	}
	for (i = 0; i < mochila->cantidad; ++i)
	{
		printf("Producto %d, peso:%d,beneficio:%d\n",i+1,mochila->conjuntoSolucion[i].peso,mochila->conjuntoSolucion[i].beneficio);
		peso+=mochila->conjuntoSolucion[i].peso;
		beneficio+=mochila->conjuntoSolucion[i].beneficio;
	}
	
	fclose(arch);
	fclose(arch2);
	fclose(arch1);
}
/*void crearProductos(PRODUCTOS lista,int numeroDeProductos)
{
	int i;

	srand(time(NULL));

	for (i = 0; i < numeroDeProductos; ++i)
	{
		lista[i].peso=(rand()%1000)+500;
		lista[i].beneficio=(rand()%200)+30;
	}
}*/


