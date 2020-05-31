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
#include "mochila.c"

#define CANTIDADPRODUCTOS (i+1)*10
#define PESO (i+1)*10

void vaciarMatriz(MOCHILAF mochila,int peso,int nProductos);
void crearMatriz(MOCHILAF mochila,PRODUCTOS lista,int peso,int nProductos);
void test(MOCHILAF mochila,PRODUCTOS lista,int j, int c);

void practica6(void);


int main(void)
{
	practica6();
	return 0;
}

void practica6(void)
{
	PRODUCTOS lista;
	MOCHILAF mochila;
	int k,i=0,contador=0,*ch=&contador,j=0,matriz[500][500],l,t,c,r,b,q=0,pes=0;
	FILE *arch=fopen("productos.txt","w");
	FILE *arch2=fopen("contador.txt","w");
	for(i=0;i<10;i++)
	{
		q=0;pes=0;
		contador=0;
		fprintf(arch, "%d\n",CANTIDADPRODUCTOS);
		mochila=crearMochila(CANTIDADPRODUCTOS);
		mochila->peso=PESO;
		lista=crearProductos(CANTIDADPRODUCTOS,mochila->peso);
		
		for(b=1;b<=CANTIDADPRODUCTOS;b++)
		{
			if(b==1)
			{
				printf("\nMOCHILA %d\n",i+1);
				printf("PESO DE LA MOCHILA: %d\n\n",PESO);
				printf("PRODUCTOS\n");
			}
			printf("Producto %d: Peso:%d, Beneficio:%d\n",b,lista[b].peso,lista[b].beneficio);	
		}
		
		
		crearMatriz(mochila,lista,PESO,CANTIDADPRODUCTOS);
		printf("\n");
		vaciarMatriz(mochila,PESO,CANTIDADPRODUCTOS);
		test(mochila,lista,CANTIDADPRODUCTOS,PESO);
		
		
		for(l=0;l<=(mochila->cantidad-1);l++)
		{
			if(l==0)
			{
				printf("\nProductos guardados");
			}
			printf("\nProducto %d: Peso:%d, Beneficio:%d\n",l+1,mochila->conjuntoSolucion[l].peso,mochila->conjuntoSolucion[l].beneficio);
			q+=mochila->conjuntoSolucion[l].beneficio;
			pes+=mochila->conjuntoSolucion[l].peso;
			if(l==(mochila->cantidad-1))
			{
				printf("Beneficio total: %d\n",q);
				printf("Peso total: %d\n",pes);	
			}
			
			
		}		
		free(mochila);
		free(lista);
	}
	fclose(arch);
	fclose(arch2);

}

void vaciarMatriz(MOCHILAF mochila,int peso,int nProductos)
{
	int i,j;
	for (i = 0; i <= nProductos; ++i)
	{
		for (j = 0; j <= peso; ++j)
		{
			if (j<(peso))
			{
				printf("%d ",mochila->matriz[i][j]);
			}
			else
			printf("%d\n",mochila->matriz[i][j]);
			
		}
	}
}

void crearMatriz(MOCHILAF mochila,PRODUCTOS lista,int peso,int nProductos)
{
	int i,j,c;

	for(i=0;i<=peso;i++)
	{
		mochila->matriz[0][i]=0;
	}
	for(i=0;i<=nProductos;i++)
	{
		mochila->matriz[j][0]=0;	
	}
	for(j=1;j<=nProductos;j++)
	{
		for (c = 1; c <=peso; ++c)
		{
			if(c<lista[j].peso)
			{
				mochila->matriz[j][c]=mochila->matriz[j-1][c];
			}
			else
			{
				if (mochila->matriz[j-1][c]>=(mochila->matriz[j-1][(c-lista[j].peso)]+lista[j].beneficio))
				{
					mochila->matriz[j][c]=mochila->matriz[j-1][c];
				}
				else
				{
					mochila->matriz[j][c]=(mochila->matriz[j-1][(c-lista[j].peso)]+lista[j].beneficio);
				}
			}
		}
	}

}

void test(MOCHILAF mochila,PRODUCTOS lista,int j, int c)
{
	if (j>0)
	{
		
		if(c<lista[j].peso)
		{
			test(mochila,lista,j-1,c);
		}
		else
		{
			
			if (((mochila->matriz[j-1][(c-lista[j].peso)])+lista[j].beneficio)>(mochila->matriz[j-1][c]))
			{
				printf("guardar objeto %d\n",j);
				mochila->conjuntoSolucion[(mochila->cantidad)].peso=lista[j].peso;
				mochila->conjuntoSolucion[(mochila->cantidad)].beneficio=lista[j].beneficio;
				mochila->cantidad++;
				test(mochila,lista,(j-1),(c-(lista[j].peso)));
			}
			else
			{
				test(mochila,lista,j-1,c);
			}
		}
	}	
}
