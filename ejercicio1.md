ENUNCIADO +-?
1.	Describir. 
2.	Explicar de forma clara, sencilla, estructurada y concisa, las ideas desarrolladas para la resolución del problema. Palabras.
3.	Deducir una cota de complejidad temporal y justificar por qué cumple la cota dada. 
4.	Dar un código fuente. Se deben incluir las partes relevantes del código como apéndice del informe impreso entregado.
5.	Realizar una experimentación computacional. preparar un conjunto de casos de test: con instancias aleatorias (detallando cómo fueron generadas) y con instancias particulares (peor/mejor). Se debe presentar adecuadamente en forma gráfica.


1.	El problema se trata de analizar la cantidad de peleas que debe haber entre un grupo de guerreros, si en cada pelea hay dos bandos a los que pueden pertenecer, para que todos pelen con todos y en cada pelea esten en uno de los dos bandos. Matemáticamente lo que proponemos para resolver en problema es: un conjunto, que se divide en dos una cantidad finita de veces tal que todos los elementos hallan estado en el conjunto opuesto a todos los demás elementos en elgun momento.
Observamos que la cantidad de peleas es logarítmica respecto a la cantidad de guerreros o elementos del conjunto principal: si n es potencia de 2 en log_2(n) y si n no es potencia de 2 en parte entera(log_2(n))+1. Esto es porque en la primer pelea, si establecemos que n/2 elementos pertenecen al bando 1 y n/2 elementos pertenecen al bando 2, ya tenemos que cada elemento peleo con la mitad del conjunto. Podemos observar que resta que cada elemento pelee contra sus compañeros de equipo actual. Por lo que, repetimos el paso anterior para cada conjunto de n/2 elementos. Y así vamos a obtener en log_2(n) peleas, que cada elemento pelea con todos los demás, porque el conjunto de n elementos se “divide” en dos cada vez; decimos “divide” porque los equipos son dos siempre: bando 1 y bando dos, pero uso la expresión para explicar cómo obtenemos el resultado que todos peleen con todos. 
Debemos notar que si la cantidad de elementos es potencia de 2, la cantidad de peleas es exactamente el logaritmo en base 2 de n. Pero si n no es potencia de 2, voy a necesitar una pelea más para que todos los elementos completen las peleas, es decir que todos terminen de pelear. Esto sucede porque la cantidad de elementos se encuentra entre 2 potencias de 2 (el. Entre 16=2^n y 32=2^(n+1)) cualesquiera, por lo tanto, las peleas anteriores dividieron a los grupos n veces, quedan menos de la mitad de elementos pelear con la anterior mitad. 
2.	no recursivamente:
    entrada: n
    generamos una matriz M de n * (log(n)+1) posiciones
    en un ciclo que itera i de 0 a log(n) inclusive:
        en un cliclo que itera j de 0 a n-1 inclusive:
            para la iteracion i asignamos M(i,j) grupo 1 y dos alternadamente a las posiciones, cambiando de grupo cada 2^i casillas
    imprimo i y luego, la matriz
3. Cota de complejidad para el algoritmo que proponemos:
Nota: parte entera superior(log(n))=peslog(n)

Creamos una matriz de peslog(n) columnas y n filas. O(n*peslog(n))
O(n*peslog(n))
O(n*peslog(n))
Algoritmo:
void kaioKen(int n){
	int i = 0;
	int j = 0;
	int filas = ceil(log2(n));
	int equipo = 1;
	int cambio = 0;
	int x = 0;
	int m [filas][n];
	for (int h = 0; h < filas; ++h)
	{
		for (int q = 0; q < n; ++q)
		{
			m[h][q] = 0;
		}
	}
	
	while(i < filas){
		cambio = pow(2,i);
		x = 0;
		j = 0;
		while(j < n){
			if(x < cambio){
				m[i][j] = equipo;
			}else{
				equipo = ((equipo +1) % 2);
				m[i][j] = equipo;
				x = 0;
			}
			j++;
			x++;
		}
		i++;
	}
	i = 0;
	j = 0;
	cout << filas << endl;
	while(i < filas){
		j = 0;
		while(j < n){
			cout << "B(" << m[i][j]+1 << "," << j+1 << ") ";
			j ++;
		}
		cout << endl;
		i++;
	}
}

4.  .
5.  .
