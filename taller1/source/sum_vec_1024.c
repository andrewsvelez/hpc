#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define N 10

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

void sumVector(int v1[], int v2[]){
	int *suma;
	suma=(int *) malloc(N* sizeof(int));
	
	for (int i = 0; i < N; i++)
	{
		suma[i]=v1[i] + v2[i];
	}
	
}


int main(){
	
	clock_t start_t, end_t;
	double total_t;
	
	
	int *v1;
	int *v2;
	
	v1=(int *) malloc(N* sizeof(int));
	v2=(int *) malloc(N* sizeof(int));
	
	iniVector(v1);
	iniVector(v2);
	
	//mostrar(v1);
	//mostrar(v2);
	
	//clock
	start_t = clock();
	
	//suma
	sumVector(v1, v2);
	
	end_t= clock();
	
	total_t= ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
	
	printf("tiempo= %f", total_t);
	
	
	return 0;
	
	
}
