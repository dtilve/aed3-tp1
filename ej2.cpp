#include <tuple>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

void genkidama(int, int, vector<tuple<int, int>>);

int main(){
	int t;
	int n;
	cin >> n >> t;
	vector<tuple<int,int>> e;
	tuple<int,int> en;
	int x;
	int y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		en = make_tuple(x,y);
		e.push_back((en));
	}
	genkidama(t, n, e);
	return 0;
}

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
