#include "ej2.h"

int main() {
	int n, t;
	cin >> n >> t;

	vectorDePosiciones_t enemigos;
	int x, y;
    for (int i = 0; i < n; i++) {
    	cin >> x >> y;
    	enemigos.push_back(make_pair(x,y));
	}

	genkidama(t, n, enemigos);
	return 0;
}

void genkidama(int t, int n, vectorDePosiciones_t enemigos) {
	vector<int> atacados;
	int genkidamasUtilizadas = 0;
	int indiceDeObjetivoPorArea = n - 1;
	// el de arriba es aquel al que quiero que le llegue la onda expansiva
	bool hayAlgunoVivo = true;

	for (int i = 0; i < n; i++) {
		cout << enemigos[i].first << "  " << enemigos[i].second << endl;
	}

	while(hayAlgunoVivo) {
		// el de abajo es aquel al que le voy a tirar la bomba
		int indiceDeObjetivo = indiceDeMenorYQueLoMata(t, indiceDeObjetivoPorArea, enemigos);
		atacados.push_back(indiceDeObjetivo + 1);
		// el +1 de arriba surge de que en el enunciado se enumeran desde el 1 y
		// nosotros enumeramos desde 0
		hayAlgunoVivo = !(indiceDeMayorXQueMata(t, indiceDeObjetivo, enemigos) == 0);
		indiceDeObjetivoPorArea = indiceDeMayorXQueMata(t, indiceDeObjetivo, enemigos) - 1;
		genkidamasUtilizadas++;
	}

	cout << genkidamasUtilizadas << endl;
	int h = 0;
	while (h < genkidamasUtilizadas) {
		if (h < genkidamasUtilizadas) {
			cout << " ";
		}
		h++;
	}
}

// Toma el t, el indice del objetivo en e y el vector de tuplas.
int indiceDeMenorYQueLoMata(int t, int indiceDeObjetivo, vectorDePosiciones_t e) {
	int j = indiceDeObjetivo - 1;
	while((j >= 0) && ((e[j].second + t) >= e[indiceDeObjetivo].second)) {
		j--;
	}
	j++;
	return j;
}

int indiceDeMayorXQueMata(int t, int indiceDeObjetivo, vectorDePosiciones_t e) {
	int distanciaDeDanio = e[indiceDeObjetivo].first + t;
	int i = indiceDeObjetivo - 1;
	while((i >= 0) && e[i].first <= distanciaDeDanio) {
		i--;
	}
	i++;
	return i;
}

/*void destruir(int t, int indiceDeObjetivo, vector<pair<int,int>> e, int genkidamas, int &indicePorArea){
	indicePorArea = indiceDeMayorXQueMata(t, indiceDeObjetivo, e) - 1;
	genkidamas++;
}*/


/* ORIGINAL QUE ANDA
void genkidama(int t, int n, vector<pair<int,int>> e){
	assert (n > 0 && n == e.size() && "La cantidad de enemigos es distinta a la cantidad de posisciones");
	vector<int> atacados;
	int j = n - 2;
	pair<int,int> obj = e[n-1];
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
