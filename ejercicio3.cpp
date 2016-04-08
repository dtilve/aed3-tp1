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

void Kamehameha(listaPos_t enemigos, Kamehamehas_t ataques, int nroAtaque) {
    if (minimo_global <= (int) ataques.size()) {
      return;
    }
    if (enemigos.size() == 0) {
        if (minimo_global > (int) ataques.size()) {
            minimo_global = (int) ataques.size();
            mejor_configuracion = ataques;
        }
    } else {
            posicion_t const enemigo = enemigos[0];
            enemigos.erase(enemigos.begin());
            atacarEnAtaqueActual(enemigo, enemigos, ataques, nroAtaque);
            atacarEnNuevoAtaque(enemigo, enemigos, ataques, nroAtaque);
            listaPos_t::iterator it = enemigos.insert(enemigos.begin(), enemigo);
        }
    }

void atacarEnAtaqueActual(posicion_t enemigo, listaPos_t restoEnemigos, Kamehamehas_t ataques, int nroAtaque) {
  for (int i = 0; i <= nroAtaque; i++) {
    Kamehameha_t atacados = ataques[i];
    if (atacados.size() == 0){
        Kamehameha_t comenzarAtaque;
        comenzarAtaque.push_back(enemigo);
        ataques[i] = comenzarAtaque;
        Kamehameha(restoEnemigos, ataques, nroAtaque);
        Kamehameha_t reestablecerAtaque;
        ataques[i] = reestablecerAtaque;
    } else if (alineados(atacados, enemigo)) {
        ataques[i].push_back(enemigo);
        Kamehameha(restoEnemigos, ataques, nroAtaque);
        ataques[i].pop_back();
      }
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

void init_time(){
    gettimeofday(&timeStart,NULL);
}

double get_time(){
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

bool esta(int j, vector<int> e, int n){
    bool b=false;
    for(int i=0; i<n; i++){
        if(e[i]==j){
           b=true;
        }
    }
    return b;
}

vector<int> generarNumeros(int n){
    vector<int> v;
    int i=0;
    int j=0;
    while(i<n){
        j=rand()%15;
        if(!esta(j,v,i)){
            v.push_back((j));
            i++;
        }
    }
    return v;
}

listaPos_t generarTuplas(int n, vector<int> v, vector<int> w){
    pair<int,int> en;
    listaPos_t e;
    for(int i=0; i<n; i++){
        en = make_pair(v[n-1-i],w[i]);
        e.push_back((en));
    }
    return e;
}
