#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > torneo;
int peleas;
// int totalEnemigos = 0;
void kaioKen(int);
void imprimirSolucion(vector<vector<int> >);
void kaioKenRec(int n, int totalEnemigos, vector<int> peleaActual);
// void inicializarMatriz(int, int, Matrix<int,int>);
// void distribuirGuerreros(int, int, Matrix<);

int main(){
	int i;
	cin >> i;
	kaioKen(i);
	imprimirSolucion(torneo);
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
	int totalEnemigos = n;
	vector<int> nuevaPelea;
	torneo.push_back(nuevaPelea);
	peleas = 0;
	kaioKenRec(n, totalEnemigos, torneo[0]);
}

void kaioKenRec(int n, int totalEnemigos, vector<int> peleaActual){
	// if (n == 1) {
	// 	peleaActual.push_back(1);
	// 	return;
	// }
	// if (n == 0) {
	// 	return;
	// }
	int cantEquipo1 = n/2;
	int cantEquipo2 = n/2;
	if (n%2 == 1) {
		cantEquipo1 ++;
	}
		for (int i = 0; i < cantEquipo1; i++) {
			peleaActual.push_back(1);
		}
		for (int i = 0; i < cantEquipo2; i++) {
			peleaActual.push_back(2);
		}
		if (n > 2) {
			std::vector<int> nuevaPelea;
			torneo.push_back(nuevaPelea);
			peleas++;
			kaioKenRec(cantEquipo1, totalEnemigos, torneo[peleas]);
			peleas--;
			kaioKenRec(cantEquipo2, totalEnemigos, torneo[peleas]);
			peleas++;
		}
}

// void kaioken(int n){
// 	if (n > totalEnemigos) {
// 		totalEnemigos = n;
// 	}
// 	if (solucion.size() == 0) {
// 		vector<int> comenzarTorneo;
// 		solucion.push_back(comenzarTorneo);
// 	}
// 	if(n == 0){
// 		return;
// 	}
// 	// if (n == 1) {
// 	// 	solucion[peleas].push_back(1);
// 	// 	return;
// 	// }
// 	if ((n%2) == 1) {
// 		if (solucion[peleas].size() < totalEnemigos) {
// 			for (int i = 0; i < (n/2)+1; i++) {
// 				solucion[peleas].push_back(1);
// 			}
// 			for (int j = 0; j < n/2; j++) {
// 				solucion[peleas].push_back(2);
// 			}
// 		}
// 		else{
// 			vector<int> nuevaPelea;
// 			peleas++;
// 			for (int i = 0; i < (n/2)+1; i++) {
// 				nuevaPelea.push_back(1);
// 			}
// 			for (int j = 0; j < n/2; j++) {
// 				nuevaPelea.push_back(2);
// 			}
// 			solucion.push_back(nuevaPelea);
// 		}
// 		if (n > 1) {
// 			kaioken((n/2)+1);
// 			kaioken(n/2);
// 		}
//
//   }
// 	else{
// 		if (solucion[peleas].size() < totalEnemigos) {
// 			for (int i = 0; i < n/2; i++) {
// 				solucion[peleas].push_back(1);
// 			}
// 			for (int j = 0; j < n/2; j++) {
// 				solucion[peleas].push_back(2);
// 			}
// 		}
// 		else{
// 			vector<int> nuevaPelea;
// 			peleas++;
// 			for (int i = 0; i < n/2; i++) {
// 				nuevaPelea.push_back(1);
// 			}
// 			for (int j = 0; j < n/2; j++) {
// 				nuevaPelea.push_back(2);
// 			}
// 			solucion.push_back(nuevaPelea);
// 		}
// 		if (n > 2) {
// 			kaioken(n/2);
// 			kaioken(n/2);
// 		}
//
// 	}
// }
void imprimirSolucion(vector<vector<int> > v) {
	std::cout << peleas << std::endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			std::cout << v[i][j];
			if (j < (v[i].size()-1)) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

// void kaioKen(int n){
// 	int filas = ceil(log2(n));
// 	int equipo = 1;
// 	int cambio = 0;
// 	int x = 0;
// 	int m [filas][n];
// 	//Inicializamos la matriz en 0
// 	for (int h = 0; h < filas; ++h)
// 	{
// 		for (int q = 0; q < n; ++q)
// 		{
// 			m[h][q] = 0;
// 		}
// 	}
// 	//Distribuimos los guerreros
// 	for (int i = 0; i < filas; i++){
// 		cambio = pow(2,i);
// 		x = 0;
// 		for(int j = 0; j < n; j++){
// 			if(x < cambio){
// 				m[i][j] = equipo;
// 			}else{
// 				equipo = ((equipo +1) % 2);
// 				m[i][j] = equipo;
// 				x = 0;
// 			}
// 			x++;
// 		}
// 	}
//
// 	cout << filas << endl;
// 	for(int i = 0; i < filas; i++){
// 		for(int j = 0; j < n; j++){
// 			cout << m[i][j]+1;
// 			if (j < n) {
// 				std::cout << " ";
// 			}
// 		}
// 		cout << endl;
// 	}
// }
