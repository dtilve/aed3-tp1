#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

int androides_global;
int minimo_global;

void Kamehameha(int N, vector<pair <int,int> > androides);

int main() {
  int N;
  cin >> N;
  vector< pair <int,int> > v;
	pair <int,int> posicion;
	for (int i = 0; i < N; i++) {
    int x = rand() %50;
    int y = rand() %50;
		posicion = make_pair(x,y);
		v.push_back((posicion));
	}
  for (int i = 0; i < N ; i++) {
    cout << "(" << v[i].first << ", " << v[i].second << ")" << endl;
  }
  Kamehameha(N,v);
  return 0;
}

void Kamehameha(int N, vector<pair <int,int> > androides) {
  int androides_local = 0;
}
