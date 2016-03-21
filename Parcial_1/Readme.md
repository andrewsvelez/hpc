#Multiplicación de matrices
####Parcial 1 - HPC
#####Introducción
Se realizó la codificación de tres algoritmos los cuales deben cumplir con el mismo objetivo, para así realizar una comparación de desempeño de ellos, el objetivo de los algoritmos consta de multiplicar dos matrices. En la carpeta *source* se encontrará la codificación de las tres soluciones, una secuencial implementada en *C* y otras dos paralelas usando *Cuda C*, una de ellas es una solución ingenua y la otra usa memoria compartida, ambos algoritmos paralelos fueron ejecutados en una GPU Nvidia Gforce GTx 780, la cual fue puesta a disposición para pruebas del curso por el semillero de la facultada de ingenierías *Sirius*.

A continuación se muestran las tablas con los datos obtenidos en las pruebas comparativas, los datos usados para el análisis son: el tiempo de ejecución del algoritmo secuencial *Ts*, el tiempo de ejecución del algoritmo paralelo ingenuo *Tp* y el tiempo de ejecución del algoritmo paralelo usando memoria compartida *Tt*, haciendo una variación en el tamaño de las matrices cuadradas para cada tabla, además se calcula la aceleración *X* de ls siguientes manera: *x = Ts / TP* en el caso de la comparación del algoritmo secuencial versus el paralelo ingenuo y *x = Ts / Tt* en el caso de la comparación del algoritmo secuencial versus el paralelo usando memoria compartida.

#####Tablas algoritmo secuencial versus paralelo ingenuo
