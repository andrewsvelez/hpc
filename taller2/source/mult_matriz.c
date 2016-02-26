#include "stdio.h"
#include "stdlib.h"

#define filas 3
#define cols 3

void iniMatriz(int **m){
	
	int i,j;
	for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
		{
			m[i][j] = (i*10)+j;
		}
		
	}
	
}

void mostrarMatriz(int **m){
	int i,j;
	for (i = 0; i < filas; i++)
	{
		
		for (j = 0; j < cols; j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
		
	}
}

void mult(int **m1, int **m2, int **m3){
	int i,j,k,aux;
	for (i = 0; i < filas; i++)
	{
		
		for (k = 0; k < cols; k++)
		{
			aux=0;
			for (j = 0; j < filas; j++)
			{
				aux += m1[i][j] * m2[j][k];
				m3[i][k] = aux; 
			}
			
		}
		
	}
}

int main(){
	int **m1;
	m1= (int **)malloc(filas*sizeof(int *));
	
	
	int i;
	//m1
	for (i = 0; i < filas; i++)
	{
		m1[i] = (int *)malloc(cols*sizeof(int));
	}
	
	//m2
	int **m2= (int **)malloc(filas*sizeof(int *));
	for (i = 0; i < filas; i++)
	{
		m2[i] = (int *)malloc(cols*sizeof(int));
	}
	
	//m3
	int **m3= (int **)malloc(filas*sizeof(int *));
	for (i = 0; i < filas; i++)
	{
		m3[i] = (int *)malloc(cols*sizeof(int));
	}
	
	
	//inicializar
	iniMatriz(m1);
	iniMatriz(m2);
	
	
	//multiplicacion
	mult(m1,m2,m3);
	
	//mostrar
	//mostrarMatriz(m2);
	mostrarMatriz(m3);
	
	return 0;
	
}
