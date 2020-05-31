	#include <stdlib.h>
#include <stdio.h>

void practica6(void);
int FibonacciTopDown(int n,int *tabla, int *c);
int FibonacciBottomUp(int n,int k, int *tabla, int *c);

int main(void)
{
	practica6();
	return 0;
}


void practica6(void)
{
	int tabla[100],tabla2[100],i,j,k,*t=tabla,*t2=tabla2,contador,contador2,*c=&contador,*c2=&contador2;
	FILE *arch=fopen("FibonacciTopDown.txt","w");
	FILE *arch2=fopen("FibonacciBottomUp.txt","w");

	for (i = 0; i < 100; ++i)
	{
		tabla[i]=-1;
	}

	tabla[0]=0;
	tabla[1]=1;

	for (i = 0; i < 100; ++i)
	{
		tabla2[i]=tabla[i];
	}
	
	k=2;

	for (i = 4; i < 41; i+=4)
	{	
		contador=0;
		contador2=0;
		printf("top:%d\n",FibonacciTopDown(i,t,c));
		printf("bottom:%d\n",FibonacciBottomUp(i,k,t2,c2));
		fprintf(arch, "%d\n",contador);
		fprintf(arch2, "%d\n",contador2);
		for (j = 0; j < 100; ++j)
		{
			tabla[j]=-1;
		}
	
		tabla[0]=0;
		tabla[1]=1;

		for (j = 0; j < 100; ++j)
		{
			tabla2[j]=tabla[j];
		}
	
		k=i;
	}
	fclose(arch2);
	fclose(arch);
}

int FibonacciTopDown(int n,int *tabla, int *c)
{
	if(tabla[n]!=-1)
	{
		(*c)++;
		(*c)++;
		return tabla[n];
	}
	tabla[n]=FibonacciTopDown(n-2,tabla,c)+FibonacciTopDown(n-1,tabla,c);
	(*c)++;
	(*c)++;
	return tabla[n];
}

int FibonacciBottomUp(int n,int k, int *tabla, int *c)
{
	int i;
	(*c)++;
	if (n<=1)
	{
		(*c)++;
		(*c)++;
		return n==0?0:1;
	}
	else
	{
		(*c)++;
		for (i = 2; i <= n; ++i)
		{
			(*c)++;
			tabla[i]=tabla[i-1]+tabla[i-2];
			(*c)++;
			
		}
		(*c)++;
	}
	(*c)++;
	return tabla[n];
}
