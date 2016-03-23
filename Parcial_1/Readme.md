#Multiplicación de matrices
###Parcial 1 - HPC
####Introducción
Se realizó la codificación de tres algoritmos los cuales deben cumplir con el mismo objetivo, para así realizar una comparación de desempeño de ellos, el objetivo de los algoritmos consta de multiplicar dos matrices. En la carpeta *source* se encontrará la codificación de las tres soluciones, una secuencial implementada en *C* y otras dos paralelas usando *Cuda C*, una de ellas es una solución ingenua y la otra usa memoria compartida, ambos algoritmos paralelos fueron ejecutados en una GPU Nvidia Gforce GTx 780, la cual fue puesta a disposición para pruebas del curso por el semillero de la facultada de ingenierías *Sirius*.

A continuación se muestran las tablas con los datos obtenidos en las pruebas comparativas, los datos usados para el análisis son: el tiempo de ejecución del algoritmo secuencial *Ts*, el tiempo de ejecución del algoritmo paralelo ingenuo *Tp* y el tiempo de ejecución del algoritmo paralelo usando memoria compartida *Tt*, haciendo una variación en el tamaño de las matrices cuadradas para cada tabla, además se calcula la aceleración *X* de ls siguientes manera: *x = Ts / TP* en el caso de la comparación del algoritmo secuencial versus el paralelo ingenuo y *x = Ts / Tt* en el caso de la comparación del algoritmo secuencial versus el paralelo usando memoria compartida.

**Nota:* *se usó un Block size de 32 en los algoritmos acá analizados*.

####Tabla algoritmo secuencial versus paralelo ingenuo
*En la siguiente tabla se encuentran registrados los tiempos promedio de ambos algoritmos para cada tamaño de matriz cuadrada*


**Tamaño matrix**|	**Ts**|	**Tp**|	**x=ts / tp**
----------|-----------|-------|-------|--------------
50|	0.0008717777778|	0.000053666667|	16.24430642
100|	0.005308111111|	0.000090666667|	58.54534314
200	|0.03116722222|	0.0002836666667	|109.8726988
250	|0.05918655556|	0.0004976666667	|118.928109
300	|0.09784588889|	0.000746777778	|131.0241036
350	|0.1564504444	|0.001157	|135.2207817
400	|0.2316638889	|0.001488888889	|155.5951493
450	|0.3450582222	|0.002317444444	|148.8960061
500	|0.4778181111	|0.002958777778	|161.4917196
550	|0.6461072222	|0.003907555556|	165.3481859
1024|	5.132635333|	0.01790988889	|286.5810818

*Ver tablas completas con el conjunto de datos con los cuales se obtuvieron los anteriores promedios*
[Ver tablas](https://docs.google.com/spreadsheets/d/1o_RRmzr3Mnd59_kJS9YmxhFSW7GESxPt83-B3bmIxpw/edit?usp=sharing)

####Gráfica de aceleración

![alt tag](media/img/secuencial_vs_ingenua_2.png)

####Tabla algoritmo secuencial versus paralelo tiling (memoria compartida)

Para el análisis de tiempos entre el algoritmo secuencial y el paralelo usando memoria compartida se tomaron tamaños para la matriz cuadrada en secciones de 32 datos o *warps*, debido a que es el tamaño de datos que se pasan de la matrix original a la sección que se copia y pasa a la sección de memoria compartida.

*En la siguiente tabla se encuentran registrados los tiempos promedio de ambos algoritmos para cada tamaño de matriz cuadrada*

**Tamaño matrix**|	**Ts**|	**Tt**|	**x=Ts / Tt**
----------|-----------|-------|-------|--------------
32	|0.0001602222222	|0.00004055555556	|3.950684932
64	|0.001513222222	|0.00004944444444	|30.60449438
96	|0.007032333333	|0.00006455555556	|108.9345955
128	|0.01049666667	|0.000089	|117.9400749
192	|0.03342966667	|0.000158	|211.5801688
224	|0.04811111111	|0.0002333333333	|206.1904762
256	|0.07272555556	|0.0002992222222	|243.0486446
512	|0.6346971111	|0.001656888889	|383.0655848
1024	|5.132635333|	0.009582	|535.6538649
1536	|24.22341856|	0.03463488889	|699.3935691

*Ver tablas completas con el conjunto de datos con los cuales se obtuvieron los anteriores promedios (ir a la segunda pestaña)*
[Ver tablas](https://docs.google.com/spreadsheets/d/1o_RRmzr3Mnd59_kJS9YmxhFSW7GESxPt83-B3bmIxpw/edit?usp=sharing)

####Gráfica de aceleración

![alt tag](media/img/secuencial_vs_tiling_2.png)

####Gráfica comparativa

En la siguiente gráfica se muestra la relación de acelaración entre los algoritmos paralelos (ingenuo y tiling) versus el algoritmo secuencial.

![alt tag](media/img/ingenua_tiling.png)

*Ver tablas completas con el conjunto de datos con los cuales se obtuvieron los anteriores promedios (ir a la tercer pestaña)*
[Ver tablas](https://docs.google.com/spreadsheets/d/1o_RRmzr3Mnd59_kJS9YmxhFSW7GESxPt83-B3bmIxpw/edit?usp=sharing)

####Conclusiones

- **1)**Los dos algoritmos implementados para su ejecución en paralelo obtuvieron un mejor desempeño con respecto a la implementación secuencial.
- **2)**Se observa que gracias al uso de memoria compartida se logra un desempeño aún mayor que la solución paralela ingenua.
- **3)**Tener cuidado con la cantidad de datos que se pasan a memoria compartida para garantizar que la matrix original sea convertida en una cantidad exacta (entera) de tiled matrixes o sección de matriz pasada a memoria compartida.
