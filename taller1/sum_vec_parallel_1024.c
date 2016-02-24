#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#include "cuda.h"


#define N 5000000

void iniVector(int v[]){
	
	for (int i = 0; i < N; i++)
	{
		v[i]=i;
	}
}

void mostrar(int v[]){
	for (int i = 0; i < N; i++)
	{
		printf("%d\n",v[i]);
	}
	
}

//kernel
__global__ void sumaV(int *d_v1, int *d_v2, int *d_v3){
	int i = (blockIdx.x * blockDim.x) + threadIdx.x;
	
	if(i<N){
	d_v3[i] = d_v1[i] + d_v2[i];
	}
	
}


int main(){
	clock_t start_t, end_t;
	double total_t;
	
	
	int *v1;
	int *v2;
	int *v3;
	
	int *d_v1;
	int *d_v2;
	int *d_v3;
	
	
	//reservar memoria en host
	v1=(int *) malloc(N* sizeof(int));
	v2=(int *) malloc(N* sizeof(int));
	v3=(int *) malloc(N* sizeof(int));
	
	//inicialziar vectores en host
	iniVector(v1);
	iniVector(v2);
	
	//clock
	start_t = clock();
	//reservadar memoria en device
	cudaMalloc((void **)&d_v1,(N* sizeof(int)));
	cudaMalloc((void **)&d_v2,(N* sizeof(int)));
	cudaMalloc((void **)&d_v3,(N* sizeof(int)));
	
	//copia host a device
	cudaMemcpy(d_v1,v1,(N* sizeof(int)), cudaMemcpyHostToDevice);
	cudaMemcpy(d_v2,v2,(N* sizeof(int)), cudaMemcpyHostToDevice);
	
	//tamaño de block e hilos
	int tamVector = N;
	float blockSize = 1024;
	int block = ceil((float)(tamVector/blockSize));
	
	//llamar a kernel
	sumaV<<<block,blockSize>>>(d_v1, d_v2, d_v3);
	
	//copia de device a host
	cudaMemcpy(v3,d_v3,(N* sizeof(int)), cudaMemcpyDeviceToHost);
	
	//mostrar
	end_t= clock();
	
	total_t= ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
	
	printf("tiempo= %f\n", total_t);
	
	//mostrar(v3);
	
	
	//liberar en host
	free(v1);
	free(v2);
	free(v3);
	
	//liberar en device
	cudaFree(d_v1);
	cudaFree(d_v2);
	cudaFree(d_v3);
	
	
}
