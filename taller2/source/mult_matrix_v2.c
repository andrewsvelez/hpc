#include "stdio.h"
#include "stdlib.h"

#define filas 2
#define cols 2

void iniMatriz(int *m){
	
	int i,j;
	for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
		{
			m[i*cols+j] = (i*10)+j;
		}
		
	}
	
}

void mostrarMatriz(int *m){
	int i,j;
	for (i = 0; i < filas; i++)
	{
		
		for (j = 0; j < cols; j++)
		{
			printf("%d ",m[i*cols+j]);
		}
		printf("\n");
		
	}
}

void mult(int *m1, int *m2, int *m3){
	int i,j,k,aux;
	for (i = 0; i < filas; i++)
	{
		
		for (k = 0; k < cols; k++)
		{
			aux=0;
			for (j = 0; j < filas; j++)
			{
				aux += m1[i*cols+j] * m2[j*cols+k];
				m3[i*cols+k] = aux; 
			}
			
		}
		
	}
}

int main(){
	int *m1;
	m1= (int *)malloc(filas*cols*sizeof(int));
	
	
	//m2
	int *m2= (int *)malloc(filas*cols*sizeof(int));
	
	//m3
	int *m3= (int *)malloc(filas*cols*sizeof(int));

	
	
	//inicializar
	iniMatriz(m1);
	iniMatriz(m2);
	
	
	//multiplicacion
	mult(m1,m2,m3);
	
	//mostrar
	//mostrarMatriz(m2);
	mostrarMatriz(m3);
	
	free(m1);
	free(m2);
	free(m3);
	
	return 0;
	
}
