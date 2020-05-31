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
#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <time.h>

typedef struct producto
{
	int beneficio;
	int peso;
	
}PRODUCTO;

typedef PRODUCTO *PRODUCTOS;

typedef struct mochila
{
	int peso;
	PRODUCTOS conjuntoSolucion;
	int matriz[500][500];
	int cantidad; //Número de objetos
}MOCHILA;

typedef MOCHILA *MOCHILAF;

MOCHILAF crearMochilas(int numeroDeMochilas);
void asignarPesosMochila(MOCHILAF mochilas,int numeroDeMochilas);
PRODUCTOS crearProductos(int numeroDeProductos,int peso);
MOCHILAF crearMochila(int numeroDeMochilas);
void mostrarMochila(MOCHILAF mochila,int opcion);




