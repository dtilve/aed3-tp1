#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

	//int n = 5;
	void kaioKen(int);
	void inicializarMatriz(int, int, int[][n]);
	void distribuirGuerreros(int, int, int[][n]);

int main(int argc, char* argv[]){
	cerr << 11<<endl;
	int i;
	cin >> i;
	cerr << 22 <<endl;
	kaioKen(i);
	return 0;
}

void inicializarMatriz(int filas, int columnas, int[][n] m){
	for (int h = 0; h < filas; h++){
		for (int q = 0; q < columnas; q++){
			m[h][q] = 0;
		}
	}
}

void distribuirGuerreros(int filas, int columnas, int[][n] m){
	int i = 0;
	int j;
	int cambio = 0;
	int equipo = 1;
	int x = 0;
	while(i < filas){
		cambio = pow(2,i);
		x = 0;
		j = 0;
		while(j < columnas){
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
}

void kaioKen(int n){
	std::cerr << "Entra a la funcion?" << std::endl;

	int filas = ceil(log2(n));
	int m[filas][n];

	inicializarMatriz(filas, n, m[][n]);
	distribuirGuerreros(filas, n, m[][n]);

	int i = 0;
	int j;
	cout << filas << endl;
	while(i < filas){
		j = 0;
		while(j < n){
			cout << m[i][j]+1;
			j ++;
			if (j < n) {
				std::cout << " ";
			}
		}
		cout << endl;
		i++;
	}
}

/* VERSIÓN NO MODULARIZADA QUE ANDA
void kaioKen(int n){
	std::cerr << "Entra a la funcion?" << std::endl;
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
	cout << filas << endl;
	while(i < filas){
		j = 0;
		while(j < n){
			cout << m[i][j]+1;
			j ++;
			if (j < n) {
				std::cout << " ";
			}
		}
		cout << endl;
		i++;
	}
}*/
