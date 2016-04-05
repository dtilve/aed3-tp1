#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// template <int filas, int columnas>
// class Matrix
// {
// 	int m [filas][columnas];
// 	Matrix();
// };
// template <int filas, int columnas>
// Matrix<filas, columnas>::Matrix(){
// 	for (int h = 0; h < filas; h++){
// 		for (int q = 0; q < columnas; q++){
// 			this[h][q] = 0;
// 		}
// 	}
// }

void kaioKen(int);
// void inicializarMatriz(int, int, Matrix<int,int>);
// void distribuirGuerreros(int, int, Matrix<);

int main(int argc, char* argv[]){
	cerr << 11<<endl;
	int i;
	cin >> i;
	cerr << 22 <<endl;
	kaioKen(i);
	return 0;
}

// void inicializarMatriz(int filas, int columnas, int** m){
// 	std::cerr << "empieza a inicializar?" << std::endl;
// 	for (int h = 0; h < filas; h++){
// 		for (int q = 0; q < columnas; q++){
// 			m[h][q] = 0;
// 		}
// 	}
// 	std::cerr << "terminana de inicializar?" << std::endl;
// }
//
// void distribuirGuerreros(int filas, int columnas, int** m){
// 	int i = 0;
// 	int j;
// 	int cambio = 0;
// 	int equipo = 1;
// 	int x = 0;
// 	while(i < filas){
// 		cambio = pow(2,i);
// 		x = 0;
// 		j = 0;
// 		while(j < columnas){
// 			if(x < cambio){
// 				m[i][j] = equipo;
// 			}else{
// 				equipo = ((equipo +1) % 2);
// 				m[i][j] = equipo;
// 				x = 0;
// 			}
// 			j++;
// 			x++;
// 		}
// 		i++;
// 	}
// }
//
// void kaioKen(int n){
//
// 	int filas = ceil(log2(n));
// 	std::cerr << "Entra a kaioken?" << std::endl;
// 	inicializarMatriz(filas, n, m);
// 	distribuirGuerreros(filas, n, m);
//
// 	int i = 0;
// 	int j;
// 	cout << filas << endl;
// 	while(i < filas){
// 		j = 0;
// 		while(j < n){
// 			cout << m[i][j]+1;
// 			cerr << m[i][j]+1;
// 			j ++;
// 			if (j < n) {
// 				cout << " ";
// 				cerr << " ";
// 			}
// 		}
// 		cout << endl;
// 		cerr << endl;
// 		i++;
// 	}
// }

// VERSIÓN NO MODULARIZADA QUE ANDA
void kaioKen(int n){
	int filas = ceil(log2(n));
	int equipo = 1;
	int cambio = 0;
	int x = 0;
	int m [filas][n];
	//Inicializamos la matriz en 0
	for (int h = 0; h < filas; ++h)
	{
		for (int q = 0; q < n; ++q)
		{
			m[h][q] = 0;
		}
	}
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
