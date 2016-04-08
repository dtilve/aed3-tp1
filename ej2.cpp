#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<pair<int,int> > vectorDePosiciones_t;

void genkidama(int, int, vectorDePosiciones_t);
int indiceDeMenorYQueLoMata(int, int, vectorDePosiciones_t);
int indiceDeMayorXQueMata(int, int, vectorDePosiciones_t);

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
		cout << atacados[h];
		if (h < genkidamasUtilizadas) {
			cout << " ";
		}
		h++;
	}
	cout << endl;
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
