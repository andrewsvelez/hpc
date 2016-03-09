# Taller 1 - Suma de vectores
Se realizó la codificación de dos algoritmos para realizar una comparación de desempeño de ambos, el objetivo de los algoritmos consta de sumar dos vectores. En la carpeta *source* se encontrará la codificación de dos soluciones, una secuencial implementada en *C* y otra paralela usando *Cuda C* y ejecutado en una GPU Nvidia Gforce, la cual fue puesta a disposición para pruebas del curso por el semillero de la facultada de ingenierías *Sirius*.

A continuación se muestran las tablas con los datos obtenidos en las pruebas comparativas, los datos usados para el análisis son: el tiempo de ejecución del algoritmo secuencial *Ts* y el tiempo de ejecución del algoritmo paralelo *Tp*, haciendo una variación en el tamaño del vector para cada tabla, además se calcula la aceleración *X* de ls siguientes manera: *x = Ts / TP*.

#### Tablas
**Tamaño del vector = 10.000.000**

Promedio|***Ts* (secuencial)**|***Tp* (paralelo)**|***X= Ts/Tp***
--------|---------------------|-------------------|--------------
        |0.025652|	0.100719|
        |0.025875|	0.104199|
        |0.025632|	0.094452|
        |0.025609|	0.118063|
        |0.025599|	0.115682|
        |0.025876|	0.12367|
        |0.025646|	0.096666|
        |0.025621|	0.118493|
        |0.025685|	0.103749|
  |*Promedios=*|**0.02568833333**|**0.1084103333**|**0.2369546568**

**Tamaño del vector = 50.000.000**

Promedio|***Ts* (secuencial)**|***Tp* (paralelo)**|***X= Ts/Tp***
--------|---------------------|--------------------|------------
    |	0.126399|	0.205388|	
  |	0.126473|	0.200034|	
  |	0.129274|	0.199052|	
  |	0.126931|	0.189096|	
  |	0.127369|	0.195527|	
  |	0.126716|	0.188485|	
  |	0.126363|	0.187812|	
  |	0.127176|	0.18582	|
  |	0.126205|	0.216893	|
|*Promedios =*|**0.1269895556**|**0.1964563333**|**0.6464009248**

**Tamaño del vector = 50.000.000**

Promedio|***Ts* (secuencial)**|***Tp* (paralelo)**|***X= Ts/Tp***
--------|---------------------|--------------------|------------
  |	0.25202|	0.285229|	
  |	0.253634|	0.286029|	
  |	0.255199|	0.285183|	
  |	0.252924|	0.288565|	
  |	0.253138|	0.285536|	
  |	0.254759|	0.290557|	
  |	0.252479|	0.273377|	
  |	0.261581|	0.282716|	
  |	0.253428|	0.286374|	
|*Promedios =*|	**0.2543513333**|	**0.2848406667**|	**0.8929600408**

**Tamaño del vector = 150.000.000**

Promedio|***Ts* (secuencial)**|***Tp* (paralelo)**|***X= Ts/Tp***
--------|---------------------|--------------------|------------
  |	0.388454|	0.407366	   |
  |	0.391532|	0.404066	|
  |	0.388543|	0.404589	|
  |	0.388847|	0.407725	|
  |	0.39064	|0.407106	|
  |	0.390506|	0.40413	|
  |	0.390846|	0.401446|	
  |	0.389785|	0.402142|	
  |	0.388971|	0.405971|	
|*Promedios =*|	**0.3897915556**|	**0.404949**|	**0.9625694978**|

**Tamaño del vector = 200.000.000**

Promedio|***Ts* (secuencial)**|***Tp* (paralelo)**|***X= Ts/Tp***
--------|---------------------|--------------------|------------
  |	0.534774|	0.509323	|
  |	0.507651|	0.510669	|
  |	0.506261|	0.509776	|
  |	0.510634|	0.507373	|
  |	0.510131|	0.505872	|
  |	0.506463|	0.509605	|
  |	0.508279|	0.514023	|
  |	0.512811|	0.510333	|
  |	0.507729|	0.50368	|
|*Promedios =*|	**0.511637**|	**0.5089615556**|	**1.005256673**|

####Gráfica!

[Aceleración](https://drive.google.com/file/d/0B3_plw75tgIpci1YRy1sakNOSzg/view?usp=sharing)
