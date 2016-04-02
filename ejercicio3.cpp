#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <stdlib.h>
using namespace std;

//typedef vector<vector<pair<int,int> > > conjuntoDeRectas;

int minimo_global;
int enemigos_global;

void Kamehameha(list<pair <int, int> > enemigos, vector<vector<pair<int,int> > > enLaMira, int indexRectaActual);
bool compartenUnaRecta (pair <int, int> E1, pair <int, int> E2, pair <int, int> E3);

int main() {
  cin >> enemigos_global;
  list<pair <int, int> > enemigos;
  vector<vector<pair<int,int> > > enLaMira;
  vector<pair <int, int> > rectaInicial;
  enLaMira.push_back(rectaInicial);
  int indexRectaActual;
	pair <int, int> posicion;
	for (int i = 0; i < enemigos_global; i++) {
    int x = rand() %5;
    int y = rand() %5;
		posicion = make_pair(x, y);
		enemigos.push_back((posicion));
	}
  //Para imprimir las tuplas generadas al azar:
  for (std::list<pair <int, int> >::iterator it=enemigos.begin(); it != enemigos.end(); ++it) {
    cout << "(" << (*it).first << ", " << (*it).second << ")" << endl;
  }
  cout << "Cantidad de enemigos: " << enemigos_global << endl;
  Kamehameha(enemigos, enLaMira, 0);
  cout << "La cantidad de Kamehamehas óptima es " << minimo_global << endl;
  return 0;
}

void Kamehameha(list<pair <int, int> > enemigos, vector<vector<pair<int,int> > > enLaMira, int indexRectaActual) {
  if (enemigos.size() < enemigos_global) {
    // si quedan androides por meter en la mira tomo el primero y lo saco de los enemigos esperando ubicación
    pair <int, int> androide = enemigos.front();
    enemigos.pop_front();

    // tomo la recta actual
    vector <pair <int ,int> > rectaActual = enLaMira[indexRectaActual];

    // quiero ver las configuraciones con esta recta como está (mientras no esté vacía),
    if (rectaActual.size() != 0){
      // entonces "cierro" la que estoy haciendo, creando una nueva
      vector <pair <int ,int> > nuevaRecta;
      vector<vector<pair<int,int> > > nuevaMira = enLaMira;
      nuevaMira.push_back(nuevaRecta);
      // y lanzo una recursión sobre el resto de los enemigos con esta nueva configuración
      // con el indice apuntando a la nueva recta
      for (int i = 1; i < enemigos.size(); i++) {
        Kamehameha(enemigos, nuevaMira, indexRectaActual++);
      }
    }

    // por otro lado intento ubicar al nuevo blanco en la recta actual
    if (rectaActual.size() > 2) {
      // si la recta actual tiene mas de dos enemigos hay que ver si es que están en la misma recta
      if (compartenUnaRecta(rectaActual[0], rectaActual[1], androide)) {
        // si puede entrar en el Kamehameha entonces lo incluyo, y hago recursion sobre el resto de los enemigos
        // con la recta actual siendo el mismo kamehameha
        rectaActual.push_back(androide);
        Kamehameha(enemigos, enLaMira, indexRectaActual);
      } else {
        // sino no hago nada, descartando tal solucion
        return;
      }
    } else {
      // si la recta actual no tiene más de dos enemigos, entonces tiene 0 o 1 y como una recta se hace entre dos puntos
      // puedo incluirlo alegremente y llamar a recursion con los enemigos restantes con la recta Actual siendo el mismo
      // Kamehameha
      rectaActual.push_back(androide);
      Kamehameha(enemigos, enLaMira, indexRectaActual);
    }
  } else {
    // si ya agoté los enemigos es porque conseguí todas las configuraciones necesarias para los kamehamehas
    // solo queda ver si la nueva solución es mejor que la que alguna vez encontré y updatearla
    int kamehamehas = enLaMira.size();
    if (kamehamehas < minimo_global){
      minimo_global = kamehamehas;
    }
  }
}

bool compartenUnaRecta (pair <int, int> primero, pair <int, int> segundo, pair <int, int> tercero) {
  int termino1 = segundo.second - primero.second;
  int termino2 = tercero.first - primero.first;
  int termino3 = tercero.second - primero.second;
  int termino4 = segundo.first - primero.first;
  return termino1*termino2 == termino3*termino4;
}
