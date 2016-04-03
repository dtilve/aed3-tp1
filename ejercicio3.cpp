#include <iostream>
#include <list>
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
typedef list<posicion_t> listaPos_t;

int minimo_global = std::numeric_limits<int>::max();
int enemigos_global;

void Kamehameha(listaPos_t enemigos,
                Kamehamehas_t enLaMira,
                int indexRectaActual);

bool compartenUnaRecta (posicion_t E1, posicion_t E2, posicion_t E3);

int main() {
    cin >> enemigos_global;
    listaPos_t enemigos;
    Kamehamehas_t enLaMira;
    Kamehameha_t kamehameha;
    enLaMira.push_back(kamehameha);
    int indexRectaActual;
	posicion_t posicion;
    srand(time(NULL));
    for (int i = 0; i < enemigos_global; i++) {
        int x = rand() %5;
        int y = rand() %5;
    	posicion = make_pair(x, y);
    	enemigos.push_back((posicion));
    }
    //Para imprimir las tuplas generadas al azar:
    for (listaPos_t::iterator it = enemigos.begin(); it != enemigos.end(); ++it) {
        cout << "(" << (*it).first << ", " << (*it).second << ")" << endl;
    }
    cout << "Cantidad de enemigos: " << enemigos_global << endl;
    Kamehameha(enemigos, enLaMira, 0);
    cout << "La cantidad de Kamehameas optima es " << minimo_global << endl;
    return 0;
}

void Kamehameha(listaPos_t enemigos, Kamehamehas_t enLaMira, int indexRectaActual) {
    cout << "La cantidad de enemigos que quedan es " << enemigos.size() << endl;
    if (enemigos.size() <= 0) {
        cout << "Enemigos agotados" << endl;
        // si ya agoté los enemigos es porque conseguí todas las configuraciones necesarias para los kamehamehas
        // solo queda ver si la nueva solución es mejor que la que alguna vez encontré y updatearla
        cout << "(índice actual - 1) = " << indexRectaActual-1
             << " el mínimo actual es " << enLaMira.size() << endl;
        minimo_global = min(minimo_global, (int)enLaMira.size());
    } else {
        // si quedan androides por meter en la mira tomo el primero y lo saco de los enemigos esperando ubicación
        posicion_t androide = enemigos.front();

        // por otro lado quiero ver las configuraciones con esta recta como está (mientras no esté vacía),
        if (enLaMira[indexRectaActual].size() != 0){
            cout << "La recta no esta vacia" << endl;
            // entonces "cierro" la que estoy haciendo, creando una nueva
            Kamehameha_t nuevoKamehameha;
            Kamehamehas_t nuevaMira = enLaMira;
            nuevaMira.push_back(nuevoKamehameha);
            // y lanzo una recursión sobre el resto de los enemigos con esta nueva configuración
            // con el indice apuntando a la nueva recta
            for (int i = 1; i < enemigos.size(); i++) {
                cout << "Llamado iterativo con la nueva mira" << endl;
                listaPos_t nuevosEnemigos = enemigos;
                nuevosEnemigos.pop_front();
                int indexRectaActual2 = indexRectaActual++;
                Kamehameha(nuevosEnemigos, nuevaMira, indexRectaActual2);
                cout << "Fin de llamado iterativo con la nueva mira" << endl;
            }
        }

        // intento ubicar al nuevo blanco en la recta actual
        if (enLaMira[indexRectaActual].size() > 2) {
            cout << "En la recta actual hay más de dos enemigos" << endl;
            // si la recta actual tiene mas de dos enemigos hay que ver si es que están en la misma recta
            posicion_t blanco1 = enLaMira[indexRectaActual].front();
            posicion_t blanco2 = enLaMira[indexRectaActual].back();
            if (compartenUnaRecta(blanco1, blanco2, androide)) {
                cout << "Coiciden en la recta" << endl;
                // si puede entrar en el Kamehameha entonces lo incluyo, y hago recursion sobre el resto de los enemigos
                // con la recta actual siendo el mismo kamehameha
                enLaMira[indexRectaActual].push_back(androide);
                cout << "agrego el androide a la recta actual y llamo a recursión sobre el mismo kamehameha" << endl;
                cout << "Llamado iterativo sobre el mismo kamehameha"<< endl;
                Kamehamehas_t copiaEnLaMira = enLaMira;
                listaPos_t nuevosEnemigos = enemigos;
                nuevosEnemigos.pop_front();
                cout << &enLaMira << " " << &copiaEnLaMira << endl;
                Kamehameha(nuevosEnemigos, copiaEnLaMira, indexRectaActual);
                cout << "Fin de llamado iterativo sobre el mismo kamehameha" << endl;
            } else {
                cout << "Descarto solución" << endl;
                // sino no hago nada, descartando tal solucion
                return;
            }
        } else {
            // si la recta actual no tiene más de dos enemigos, entonces tiene 1 y como una recta se hace entre dos puntos
            // puedo incluirlo alegremente y llamar a recursion con los enemigos restantes con la recta Actual siendo el mismo
            // Kamehameha
            cout << "agrego androide puesto que no tiene más de dos enemigos" << endl;
            cout << androide.first << " " << androide.second << endl;
            Kamehamehas_t copiaEnLaMira = enLaMira;
            copiaEnLaMira[indexRectaActual].push_back(androide);
            listaPos_t nuevosEnemigos = enemigos;
            nuevosEnemigos.pop_front();
            cout << "Llamado iterativo con el nuevo androide en el mismo Kamehameha"<< endl;
            Kamehameha(nuevosEnemigos, copiaEnLaMira, indexRectaActual);
            cout << "Fin de llamado iterativo con el nuevo androide en el mismo Kamehameha" << endl;
        }
    }
}

bool compartenUnaRecta (posicion_t primero, posicion_t segundo, posicion_t tercero) {
    int termino1 = segundo.second - primero.second;
    int termino2 = tercero.first - primero.first;
    int termino3 = tercero.second - primero.second;
    int termino4 = segundo.first - primero.first;
    return termino1*termino2 == termino3*termino4;
}
