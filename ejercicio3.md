Holaa!
les queria comentar la idea que estuve hablando ayer con julian, porque aparentemente el ejercicio que hicimos ayer tiene mucho que ver con el ejercicio 3, y creo que encontramos un camino para hacerlo.
La idea es:

nosotros tenemos una funcion Backteracking() que recibe: 
-elconjunto de elementos para tomar deciciones (las rectas o los puntos de ayer) e, 
-un conjunto de soluciones s
-el minimo relativo (cantidad minima de rectas o conjuntos de ayer)

el algoritmo deberia funcionar de la siguiente manera:
iteracion 1 como no hay soluciones aun, coloco un punto en una posible recta {p1}
iteraciones siguientes, para cada elemento solucion alterior, coloco al siguiente elemento en ella {{p1,p2}}
                        coloco el elemento en una recta separada {{p1},{p2}}
escribo una mas,  {{p1,p2,p3}} {{p1,p2},{p3}} 
                  {{p1,p3},{p2}} {{p1},{p2,p3}} {{p1},{p2},{p3}}
otra, para ver complejidad, {{p1,p2,p3,p4}} {{p1,p2,p3},{p4}}
      {{p1,p2,p4},{p3}} {{p1,p2},{p3,p4}} {{p1,p2},{p3},{p4}}
      {{p1,p3,p4},{p2}} {{p1,p3},{p2,p4}} {{p1,p3},{p2},{p4}} 
      {{p1,p4},{p2,p3}} {{p1},{p2,p3,p4}} {{p1},{p2,p3},{p4}} 
      {{p1,p4},{p2},{p3}} {{p1},{p2,p4},{p3}} {{p1},{p2},{p3,p4}} {{p1},{p2},{p3},{p4}}

la condicion aca es que todos los puntos de la recta tienen que estar alineados, sino la solucion no es correcta. 

algoritmo: -falta el caso: poner al elemento en una recta a "el solo" osea ponerlo en una solucion vacia-

bactracking(p,s,min){
    if(vacio?(p)){
        return s
    }else{
        while(s != vacio()){
            sol = #bactracking(sinUno(p),sinUno(s) union dameUno(s):dameUno(p) ,min)
            s=sinUnos(s)
            if(sol < min){
                min = sol
            }
        }
    }
}

la complejidad de esto es algo asi, me dijo julian -algo no me cierra- :
h(0,#s)=#s
hojas(es,s) = hojas(es-1,#s) + hojas(es-1,#s+1)
            = hojas(es-1,#s) + 1 //para mi......


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
