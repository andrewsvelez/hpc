#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#include "cuda.h"

#define filas 32
#define cols 32

#define TILE_WIDTH 32

void iniMatriz(int *m){
	
	int i,j;
	for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
		{
			m[i*cols+j] = 1;
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
__global__ void mult_m(int *d_m1, int *d_m2, int *d_m3){
	
  int i,j,aux;

  j = blockIdx.y*blockDim.y+threadIdx.y;
  i = blockIdx.x*blockDim.x+threadIdx.x;
	
	if(i<cols && j<filas){
    	aux=0;
	   for(int k=0;k<cols;k++){
		 aux+= d_m1[j*cols+k] * d_m2[k*cols+i];
		}
		d_m3[i*cols+j]=aux;
	}
}

//kernel tiling
__global__ void mult_m_tiling(int *d_m1, int *d_m2, int *d_m3){
	
	__shared__ int m1_ds[TILE_WIDTH][TILE_WIDTH];
    __shared__ int m2_ds[TILE_WIDTH][TILE_WIDTH];

    int bx = blockIdx.x;
    int by = blockIdx.y;
    int tx = threadIdx.x;
    int ty = threadIdx.y;

    int row = by * TILE_WIDTH + ty;
    int col = bx * TILE_WIDTH + tx;

    float aux = 0;

    for(int m = 0; m < cols / TILE_WIDTH; ++m){
	m1_ds[ty][tx] = d_m1[row*cols + m*TILE_WIDTH + tx];
	m2_ds[ty][tx] = d_m2[(m*TILE_WIDTH + ty) * cols + col];
	__syncthreads();

	for(int k = 0; k < TILE_WIDTH; ++k){
		aux += m1_ds[ty][k] * m2_ds[k][tx];	    
	}
	__syncthreads();
    }
    d_m3[row*cols+col] = aux;
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
	//mult_m<<<dimGrid,dimBlock>>>(d_m1, d_m2, d_m3);
	mult_m_tiling<<<dimGrid,dimBlock>>>(d_m1, d_m2, d_m3);
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
