#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


void kaioKen(int);

int main(int argc, char* argv[]){
	cerr << 11<<endl;
	int i;
	cin >> i;
	cerr << 22 <<endl;
	kaioKen(i);
	return 0;
}

void kaioKen(int n){
	int filas = ceil(log2(n));
	int equipo = 1;
	int cambio = 0;
	int x = 0;
	int m [filas][n];

	//Distribuimos los guerreros
	for (int i = 0; i < filas; i++){
		cambio = pow(2,i);
		x = 0;
		for(int j = 0; j < n; j++){
			if(x < cambio){
				m[i][j] = equipo;
			}else{
				equipo = ((equipo +1) % 2);
				m[i][j] = equipo;
				x = 0;
			}
			x++;
		}
	}

	cout << filas << endl;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < n; j++){
			cout << m[i][j]+1;
			if (j < n) {
				std::cout << " ";
			}
		}
		cout << endl;
	}
}
