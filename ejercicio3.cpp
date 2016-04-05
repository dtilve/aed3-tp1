#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <limits>
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
bool alineados (Kamehameha_t atacados, posicion_t enemigo);
void reporte(listaPos_t enemigos, Kamehamehas_t ataques, int nroAtaque);
int buscarPosicion(const posicion_t& enemigo);
void mostrarSolucion();

int main() {
    int cantEnemigos;
    cin >> cantEnemigos;
    listaPos_t enemigos;
    Kamehamehas_t enLaMira;
    Kamehameha_t kamehameha;
    enLaMira.push_back(kamehameha);
    int indexRectaActual;
	  posicion_t posicion;
    //srand(time(NULL));
    for (int i = 0; i < cantEnemigos; i++) {
        int x;
        //x = rand() %10;
        int y;
        //y = rand() %10;
        std::cin >> x >> y;
    	posicion = make_pair(x, y);
    	enemigos.push_back((posicion));
    }
    //Para imprimir las tuplas generadas al azar:
    enemigos_global = enemigos;
    for (listaPos_t::iterator it = enemigos.begin(); it != enemigos.end(); ++it) {
            cerr << (*it).first << " " << (*it).second << endl;
    }
    Kamehameha(enemigos, enLaMira, 0);
    mostrarSolucion();
    return 0;
}

void Kamehameha(listaPos_t enemigos, Kamehamehas_t ataques, int nroAtaque) {
    if (enemigos.size() == 0) {
        if (minimo_global > (int)ataques.size()) {
            minimo_global = (int) ataques.size();
            mejor_configuracion = ataques;
        }
    } else {
        for (int i = 0; i < enemigos.size(); i++) {
            posicion_t const enemigo = enemigos[i];
            enemigos.erase(enemigos.begin()+i);
            atacarEnAtaqueActual(enemigo, enemigos, ataques, nroAtaque);
            atacarEnNuevoAtaque(enemigo, enemigos, ataques, nroAtaque);
            listaPos_t::iterator it = enemigos.insert(enemigos.begin()+i, enemigo);
        }
    }
}

void atacarEnAtaqueActual(posicion_t enemigo, listaPos_t restoEnemigos, Kamehamehas_t ataques, int nroAtaque) {
    Kamehameha_t atacados = ataques[nroAtaque];
    if (atacados.size() == 0){
        Kamehameha_t comenzarAtaque;
        comenzarAtaque.push_back(enemigo);
        ataques[nroAtaque] = comenzarAtaque;
        Kamehameha(restoEnemigos, ataques, nroAtaque);
        Kamehameha_t reestablecerAtaque;
        ataques[nroAtaque] = reestablecerAtaque;
    } else if (alineados(atacados, enemigo)) {
        ataques[nroAtaque].push_back(enemigo);
        Kamehameha(restoEnemigos, ataques, nroAtaque);
        ataques[nroAtaque].pop_back();
    } else {
        return;
    }
}

void atacarEnNuevoAtaque(posicion_t enemigo, listaPos_t restoEnemigos, Kamehamehas_t ataques, int nroAtaque) {
    if (ataques[nroAtaque].size() > 0) {
        Kamehameha_t comenzarAtaque;
        comenzarAtaque.push_back(enemigo);
        ataques.push_back(comenzarAtaque);
        nroAtaque++;
        Kamehameha(restoEnemigos, ataques, nroAtaque);
        nroAtaque--;
        ataques.pop_back();
    }
}

bool alineados (Kamehameha_t atacados, posicion_t enemigo) {
    if (atacados.size() == 0 || atacados.size() == 1) {
        return true;
    } else {
        posicion_t primero = atacados[0];
        posicion_t segundo = atacados[1];
        int termino1 = segundo.second - primero.second;
        int termino2 = enemigo.first - primero.first;
        int termino3 = enemigo.second - primero.second;
        int termino4 = segundo.first - primero.first;
        return termino1*termino2 == termino3*termino4;
    }
}

void reporte(listaPos_t enemigos, Kamehamehas_t ataques, int nroAtaque) {
    cout << "enemigos: ";
    for (listaPos_t::iterator itL = enemigos.begin(); itL != enemigos.end(); ++itL) {
        cout << "(" << (*itL).first << ", " << (*itL).second << ")";
        if (itL!= enemigos.end()) {
            cout << ", ";
        }
    }
    cout << endl ;
    for (int i = 0; i < ataques.size(); i++) {
        Kamehameha_t ataqueEnIdx = ataques[i];
        cout << "[";
        for (Kamehameha_t::iterator it = ataqueEnIdx.begin(); it != ataqueEnIdx.end(); ++it) {
            cout << "(" << (*it).first << ", " << (*it).second << "), ";
            if (it!= ataqueEnIdx.end()){ cout << ", "; };
        }
        cout << "]" << endl;
    }
}

void mostrarSolucion() {
    cout << mejor_configuracion.size() << endl;
    for (int i = 0; i < mejor_configuracion.size(); i++) {
        Kamehameha_t ataqueEnIdx = mejor_configuracion[i];
        cout << ataqueEnIdx.size() << " ";
        for (Kamehameha_t::iterator it = ataqueEnIdx.begin(); it != ataqueEnIdx.end(); ++it) {
            cout << buscarPosicion(*it)+1 << " ";
        }
        cout << endl;
    }

    cerr << mejor_configuracion.size() << endl;
    for (int i = 0; i < mejor_configuracion.size(); i++) {
        Kamehameha_t ataqueEnIdx = mejor_configuracion[i];
        cerr << ataqueEnIdx.size() << " ";
        for (Kamehameha_t::iterator it = ataqueEnIdx.begin(); it != ataqueEnIdx.end(); ++it) {
            cerr << buscarPosicion(*it)+1 << " ";
        }
        cerr << endl;
    }
}

int buscarPosicion(const posicion_t& enemigo) {
    listaPos_t::iterator it = find (enemigos_global.begin(), enemigos_global.end(), enemigo);
    return distance(enemigos_global.begin(), it);
}
