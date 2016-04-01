Problema 3: Kamehameha
Gokú se está enfrentando a N androides y necesita destruirlos con la menor cantidad de Kamehamehas posibles. Los enemigos ode Gokú se encuentran en posiciones (X_i, Y_i) y los Kamehameha recorren una semirrecta desde donde Gokú lo lance, en cualquier dirección que Gokú lo decida. ¿Cúantos Kamehamehas necesita Gokú para desturir a todos los androides del doctor Maki Gero? Se pide escribir un algoritmo que tome la cantidad de androides N y las posiciones (X_i, Y_i) de los mismos y decida cuántos Kamehameha debe lanzar Gokú y a qué enemigos destruye con cada Kamehameha. Si hay más de una solución óptima, el algoritmo puede devolver cualquiera de ellas. Se pide utilizar la técnica de Backtracking y elaborar podas y estrategias para mejorar los tiempos de ejecución; éstas deberán estar apropiadamente documentadas en el informe. El algoritmo debe tener una complejidad temporal O(N^N+2) o mejor.
Consideraciones

Formato de entrada: La primera línea consta de un entero positivo N, que indica la cantidad de androides. A esta línea le siguen N líneas, una para cada androide, cada línea conteniendo dos enteros Xi e Yi (ambos enteros no negativos y separados por un espacio) indicando la posición del androide en cuestión. La entrada contará con el siguiente formato:

N
X1 Y1
X2 Y2
...
XN YN

Formato de salida: La primera línea de la salida debe contener un número M indicando la cantidad de Kamehamehas que Gokú debe lanzar. A esta línea deberán seguirle M líneas, una para cada Kamehameha, cada línea conteniendo un entero Ci, que indique la cantidad de enemigos que derrota con el i-ésimo Kamehameha, seguido de Ci enteros indicando los índices Eij de los enemigos que derrota con el i-ésimo Kamehameha. La salida tendrá el siguiente formato:

M
C1 E11 ... E1C1
...
CM EM1 ... EMCM

Los números Eij deben ser N números entre 1 y N, sin repetidos.

Enunciado

1. Describir. 
2. Explicar de forma clara, sencilla, estructurada y concisa, 
las ideas desarrolladas para la resolución del problema. Palabras. 
3. Deducir una cota de complejidad temporal y justificar por qué cumple la cota dada. 
4. Dar un código fuente. Se deben incluir las partes relevantes del código como apéndice del informe impreso entregado. 
5. Realizar una experimentación computacional. preparar un conjunto de casos de test: con instancias aleatorias 
(detallando cómo fueron generadas) y con instancias particulares (peor/mejor). Se debe presentar adecuadamente en forma gráfica.

1. a 
2. a
3. a
4. a
5. a
