Mediciones
===================
---------------

Problema 1: Kaio Ken
-------------

1 -> 1e-06
2 -> 5e-06
4 -> 6e-06
8 -> 7e-06
16 -> 1.2e-05
32 -> 1.3e-05
64 -> 1.4e-05
128 -> 1.5e-05
256 -> 1.7e-05
512 -> 2.1e-05
2^10 -> 2,9e-05
2^11 -> 4.7e-05
2^12 -> 8.7e-05
2^13 -> 0,00017
2^14 -> 0.000346
2^15 -> 0,000733
2^16 -> 0,001519
2^17 and on -> segfault


#### Consideraciones
Formato de entrada: La única línea de la entrada contiene un entero positivo N, que indica la cantidad de guerreros, con el siguiente formato:

    N

Formato de salida: La salida debe contener una línea con la mínima cantidad de peleas que deben realizarse en el entrenamiento, seguido por el bando de cada guerrero en cada pelea, con el siguiente formato:

    P
    B(1,1) B(1,2) ... B(1,N)
    ...
    B(P,1) B(P,2) ... B(P,N)

donde `P` es la cantidad de peleas y `B(i,j)` es el bando del guerrero `j` en la pelea i, siendo `B(i,j)` 1 o 2.


-----------
Problema 2: Genkidama
-------------

<center>
![DBZ_SagaFrieza-Genkidama](http://vignette1.wikia.nocookie.net/dragonball/images/2/2d/GokuSpiritBombFrieza02.png/revision/latest?cb=20110919024106&path-prefix=es)
</center>

El planeta Tierra está en peligro. N soldados de Freezer están parados en distintos puntos (Xi,Yi) sobre nuestro planeta y están dispuestos a acabar con toda la humanidad. Para esto, Gokú desea lanzarles algunas Genkidamas que puedan acabar con ellos. Los puntos cumplen con la propiedad X_1 > X_2 > ... > X_N ≥ 0 y 0 ≤ Y_1 < Y_2 < ... < Y_N. Gokú lanzará las Genkidamas a puntos donde hay enemigos, por lo que si en un punto no hay un enemigo no puede lanzar una Genkidama a ese punto (sí puede lanzarla si había un enemigo que ya fue destruido por Gokú con una Genkidama previa, para asegurarse que el enemigo no reviva). Una Genkidama lanzada al punto (X, Y) destruye a todos los enemigos que están en el rectángulo con lados paralelos a los ejes y extremos en (0, 0) y (X + T , Y + T ).
¿Cuántas Genkidamas necesita lanzar Gokú, como mínimo, para poder acabar con todos sus enemigos?
Se pide escribir un algoritmo que tome el número de enemigos de Gokú, las posiciones de los mismos, y el valor de T, y que indique la mínima cantidad de Genkidamas debe lanzar Gokú para acabar con todos sus enemigos, junto con los índices de aquellos enemigos a cuyas posiciones lanza las Genkidamas. El algoritmo debe tener una complejidad temporal O(N), siendo N la cantidad de enemigos. Si hay más de una solución óptima cualquiera de ellas es considerada válida.

#### Consideraciones

Formato de entrada: La primera línea consta de un valor entero positivo N, que indica la cantidad de enemigos, y un entero positivo T, que indica que una Genkidama lanzada al punto (X,Y) destruye a todos los enemigos en el rectángulo con lados paralelos a los ejes y extremos en (0,0) y (X+T, Y+T). A esta línea le siguen N líneas, una para cada enemigo. La entrada contará con el siguiente formato:

    N T
    X1 Y1
    X2 Y2 ... XN YN

donde `Xi` e `Yi` son enteros no negativos, decrecientes los Xi y crecientes los Yi, que indican las posiciones de los enemigos de Gokú.
Formato de salida: La primera línea de la salida debe contener un entero `G` indicando la cantidad de Genkidamas a lanzar por Gokú. A esta línea debe seguirle una línea con los índices `Ei` de los enemigos a los que debe lanzarle las Genkidamas, contando la salida con el siguiente formato:

    G
    E1 E2 ... EG

indicando que Gokú debe lanzarle una Genkidama a los enemigos en posiciones `(XE1,YE1), (XE2,YE2), ..., (XEG, YEG)`.

----------
Problema 3: Kamehameha
-------------

![DBZ_SagaFrieza-Kamehameha](http://dragonballuniverse.com/wp-content/uploads/2015/03/Goku-Kamehameha-e1427316789719.png)

Gokú se está enfrentando a N androides y necesita destruirlos con la menor cantidad de Kamehamehas posibles. Los enemigos ode Gokú se encuentran en posiciones (X_i, Y_i) y los Kamehameha recorren una semirrecta desde donde Gokú lo lance, en cualquier dirección que Gokú lo decida. ¿Cúantos Kamehamehas necesita Gokú para desturir a todos los androides del doctor Maki Gero?
Se pide escribir un algoritmo que tome la cantidad de androides N y las posiciones (X_i, Y_i) de los mismos y decida cuántos Kamehameha debe lanzar Gokú y a qué enemigos destruye con cada Kamehameha. Si hay más de una solución óptima, el algoritmo puede devolver cualquiera de ellas. Se pide utilizar la técnica de *Backtracking* y elaborar podas y estrategias para mejorar los tiempos de ejecución; éstas deberán estar apropiadamente documentadas en el informe. El algoritmo debe tener una complejidad temporal O(N^N+2) o mejor.

#### Consideraciones

Formato de entrada: La primera línea consta de un entero positivo N, que indica la cantidad de androides. A esta línea le siguen N líneas, una para cada androide, cada línea conteniendo dos enteros `Xi` e `Yi` (ambos enteros no negativos y separados por un espacio) indicando la posición del androide en cuestión. La entrada contará con el siguiente formato:

    N
    X1 Y1
    X2 Y2
    ...
    XN YN

Formato de salida: La primera línea de la salida debe contener un número `M` indicando la cantidad de Kamehamehas que Gokú debe lanzar. A esta línea deberán seguirle M líneas, una para cada Kamehameha, cada línea conteniendo un entero `Ci`, que indique la cantidad de enemigos que derrota con el i-ésimo Kamehameha, seguido de `Ci` enteros indicando los índices `Eij` de los enemigos que derrota con el i-ésimo Kamehameha. La salida tendrá el siguiente formato:

    M
    C1 E11 ... E1C1
    ...
    CM EM1 ... EMCM

Los números `Eij` deben ser N números entre 1 y N, sin repetidos.
