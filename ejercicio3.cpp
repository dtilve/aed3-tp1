#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <limits>
#include <sys/time.h>
#include <cstdio>
#include "ejercicio3.h"
using namespace std;

typedef pair<int,int> posicion_t;
typedef vector<posicion_t> Kamehameha_t;
typedef vector<Kamehameha_t> Kamehamehas_t;
typedef deque<posicion_t> listaPos_t;

int minimo_global = std::numeric_limits<int>::max();
listaPos_t enemigos_global;
Kamehamehas_t mejor_configuracion;
void Kamehameha(listaPos_t enemigos,
                Kamehamehas_t enLaMira,
                int indexRectaActual);
void atacarEnAtaqueActual(posicion_t enemigo,
                          listaPos_t restoEnemigos,
                          Kamehamehas_t ataques,
                          int nroAtaque);
void atacarEnNuevoAtaque(posicion_t enemigo,
                         listaPos_t restoEnemigos,
                         Kamehamehas_t ataques,
                         int nroAtaque);


void atacarEnNuevoAnterior(posicion_t enemigo,
                        listaPos_t restoEnemigos,
                        Kamehamehas_t ataques,
                        int nroAtaque);


bool alineados (Kamehameha_t atacados, posicion_t enemigo);
void reporte(listaPos_t enemigos, Kamehamehas_t ataques, int nroAtaque);
int buscarPosicion(const posicion_t& enemigo);
void mostrarSolucion();
timeval timeStart,timeEnd;
listaPos_t generarTuplas(int n, vector<int> v, vector<int> w);
vector<int> generarNumeros(int n);
bool esta(int j, vector<int> e, int n);
double get_time();
void init_time();

int main() {
    srand(time(NULL));
    int cantEnemigos;
    cin >> cantEnemigos;
    listaPos_t enemigos;
    Kamehamehas_t enLaMira;
    Kamehameha_t kamehameha;
    enLaMira.push_back(kamehameha);
    vector<int> v;
    vector<int> w;
    v=generarNumeros(cantEnemigos);
    w=generarNumeros(cantEnemigos);
    enemigos=generarTuplas(cantEnemigos,v,w);

    enemigos_global = enemigos;
    for (listaPos_t::iterator it = enemigos.begin(); it != enemigos.end(); ++it) {
            cerr << (*it).first << " " << (*it).second << endl;
    }

    init_time();
    Kamehameha(enemigos, enLaMira, 0);
    cout << "El tiempo que tardo es:" << get_time() << endl;
    mostrarSolucion();
    return 0;
}

