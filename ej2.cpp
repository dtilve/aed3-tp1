#include <tuple>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include<cstdio>
#include<sys/time.h>
using namespace std;

void genkidama(int, int, vector<tuple<int, int>>);
int indiceDeMenorYQueLoMata(int, int, vector<tuple<int,int>>);
int indiceDeMayorXQueMata(int, int, vector<tuple<int,int>>);

timeval timeStart,timeEnd;

void init_time()
{
    gettimeofday(&timeStart,NULL);
}

double get_time()
{
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

bool esta(int j, vector<int> e, int n){
	bool b=false;
	for(int i=0; i<n; i++){
		if(e[i]==j){
		   b=true;
		}
	}	
	return b;
}

vector<int> generarNumeros(int n){
	vector<int> v;
	int i=0;
	int j=0;	
	while(i<n){
		j=rand()%100;
		if(!esta(j,v,i)){
			v.push_back((j));
			i++;	
		}
	}
	return v;
}

vector<tuple<int,int>> generarTuplas(int n, vector<int> v, vector<int> w){
	tuple<int,int> en;
	vector<tuple<int,int>> e;
	for(int i=0; i<n; i++){
		en = make_tuple(v[n-1-i],w[i]);
		e.push_back((en));
	}
	return e;
}

vector<int> ordenar(vector<int> v, int n){
	int aux = 0;
	for(int j=0; j<n; j++){
		for(int i=0; i < (n-1); i++){
			if(v[i]>v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
			}
		}
	}
	return v;
}

int main(){
	srand(time(NULL));
	int t;
	int n;
	cin >> n >> t;
	vector<tuple<int,int>> e;
	vector<int> v;
	vector<int> w;
	v=generarNumeros(n);
	w=generarNumeros(n);
	v = ordenar(v,n);
	w = ordenar(w,n);	
	e=generarTuplas(n,v,w);	
	genkidama(t, n, e);
	return 0;
}

// Toma el t, el indice del objetivo en e y el vector de tuplas.
int indiceDeMenorYQueLoMata(int t, int indiceDeObjetivo, vector<tuple<int,int>> e){
	int j = indiceDeObjetivo - 1;
	while((j >= 0) && ((get<1>(e[j]) + t) >= get<1>(e[indiceDeObjetivo]))){
		j--;
	}
	j++;
	return j;
}

int indiceDeMayorXQueMata(int t, int indiceDeObjetivo, vector<tuple<int,int>> e){
	int distanciaDeDano = get<0>(e[indiceDeObjetivo]) + t;
	int i = indiceDeObjetivo - 1;
	while((i >= 0) && (get<0>(e[i]) <= distanciaDeDano)){
		i--;
	}
	i++;
	return i;
}

// MODULARIZADO
void genkidama(int t, int n, vector<tuple<int,int>> e){
	assert (n > 0 && n == e.size() && "La cantidad de enemigos es distinta a la cantidad de posisciones");
	vector<int> atacados;
	int genkidamasUtilizadas = 0;
	int indiceDeObjetivoPorArea = n-1;
	// el de arriba es aquel al que quiero que le llegue la onda expansiva
	bool hayAlgunoVivo = true;
	
	for (int i = 0; i < n; ++i)
	{
		cout << get<0>(e[i]) << "  " << get<1>(e[i]) << endl;
	}

	init_time();	
	while(hayAlgunoVivo){
		// el de abajo es aquel al que le voy a tirar la bomba
		int indiceDeObjetivo = indiceDeMenorYQueLoMata(t, indiceDeObjetivoPorArea, e);
		atacados.push_back(indiceDeObjetivo + 1);
		// el +1 de arriba surge de que en el enunciado se enumeran desde el 1 y
		// nosotros enumeramos desde 0
		hayAlgunoVivo = !(indiceDeMayorXQueMata(t, indiceDeObjetivo, e) == 0);
		indiceDeObjetivoPorArea = indiceDeMayorXQueMata(t, indiceDeObjetivo, e) - 1;
		genkidamasUtilizadas++;
	}
	cout << "el tiempo fue " << get_time() << endl;

	std::cout << "genkidamasUtilizadas" << genkidamasUtilizadas << std::endl;
	int h = 0;
	while (h < genkidamasUtilizadas) {
			std::cout << "atacados" << atacados[h];
			h++;
			if (h < genkidamasUtilizadas) {
					std::cout << " ";
			}
	}
	std::cout << std::endl;
}


/* ORIGINAL QUE ANDA
void genkidama(int t, int n, vector<tuple<int,int>> e){
	assert (n > 0 && n == e.size() && "La cantidad de enemigos es distinta a la cantidad de posisciones");
	vector<int> atacados;
	int j = n - 2;
	tuple<int,int> obj = e[n-1];
	int genki = 0;
	bool hayAlgunoVivo = true;
	while(hayAlgunoVivo){
		while((j >= 0) && ((get<1>(e[j]) + t) >= get<1>(obj))){
			j--;
		}
		atacados.push_back(j + 2);
		genki ++;
		if (j < 0) {
			hayAlgunoVivo = false;
		}
		int dis = get<0>(e[j + 1]) + t;
		int i = j;
		while((i >= 0) && (get<0>(e[i]) <= dis)){
			i--;
		}
		// Si el de mas a la derecha tambien fuera a ser matado, el while
		// de arriba da i igual a -1 y lo de abajo se indefine :(
		if (get<0>(e[i]) <= dis){
			hayAlgunoVivo = false;
		}
		obj = e[i];
		j = i;
	}

		std::cout << genki << std::endl;
		int h = 0;
		while (h < genki) {
				std::cout << atacados[h];
				h++;
				if (h < genki) {
						std::cout << " ";
				}
		}
}
*/
