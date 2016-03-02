#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#include "cuda.h"

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

//kernel
__global__ void mult_m (int *d_m1, int *d_m2, int *d_m3){
	int i = (blockIdx.x * blockDim.x) + threadIdx.x;
	int j = (blockIdx.y * blockDim.y) + threadIdx.y;
	int k,aux;
	aux=0;
	if((i< filas) && (j<cols)){
		aux=0;
		for (k = 0; k <cols*filas ; k++)
		{
			aux += d_m1[i*cols+j] * d_m2[j*cols+k];
		}
		d_m3[i*cols+k] = aux;
		
	}
	
}

int main(){
	clock_t start_t, end_t;
	double total_t;
	
	//reservar memoria en host
	//m1
	int *m1;
	m1= (int *)malloc(filas*cols*sizeof(int));
	
	
	//m2
	int *m2= (int *)malloc(filas*cols*sizeof(int));
	
	//m3
	int *m3= (int *)malloc(filas*cols*sizeof(int));
	
	//inicializar
	iniMatriz(m1);
	iniMatriz(m2);
	
	//reservadar memoria en device
	int *d_m1;
	int *d_m2;
	int *d_m3;
	
	
	cudaMalloc((void **)&d_m1,(filas*cols* sizeof(int)));
	cudaMalloc((void **)&d_m2,(filas*cols* sizeof(int)));
	cudaMalloc((void **)&d_m3,(filas*cols* sizeof(int)));
	
	
	//copia host a device
	cudaMemcpy(d_m1,m1,(filas*cols* sizeof(int)), cudaMemcpyHostToDevice);
	cudaMemcpy(d_m2,m2,(filas*cols* sizeof(int)), cudaMemcpyHostToDevice);
	
	//tamaño de block e hilos
	int blockSize = 32;
	dim3 dimBlock(blockSize, blockSize, 1);
	dim3 dimGrid(ceil(cols/float(blockSize)),ceil(cols/float(blockSize)),1);
	
	//clock
	start_t = clock();
	
	//llamar a kernel
	mult_m<<<dimGrid,dimBlock>>>(d_m1, d_m2, d_m3);
	
	//copia de device a host
	cudaMemcpy(m3,d_m3,(filas*cols* sizeof(int)), cudaMemcpyDeviceToHost);
	
	//mostrar
	end_t= clock();
	
	total_t= ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
	
	printf("tiempo= %f\n", total_t);
	
	mostrarMatriz(m3);
	
	//liberar en host
	free(m1);
	free(m2);
	free(m3);
	
	//liberar en device
	cudaFree(d_m1);
	cudaFree(d_m2);
	cudaFree(d_m3);
	
}
