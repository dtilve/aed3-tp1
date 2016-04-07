#include <stdio.h>      /* stdin, stdout */
#include <fstream>      /* basic file operations */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <string>
#include <time.h>       /* time */
using namespace std;

// random tuple generator
void randomInstanceGenerator(int s, int n, ofstream &file);

int main() {
    int s, n;
    cout << "Ingrese un número para limitar los ejes x e y" << endl;
    cin >> s;
    cout << "Ingrese el tamaño de la entrada a ser generada" << endl;
    cin >> n;
    while (n == 0) {
        cout << "0 es un caso demasiado trivial :)" << endl;
        cin >> n;
    }
    ofstream file;
    string fileName = "instancia" + to_string(s) + ".txt";
    file.open(fileName, fstream::out);
    randomInstanceGenerator(s, n, file);
    file.close();
    return 0;
}

void randomInstanceGenerator(int s, int n, ofstream &file) {
    // random seed
    srand(time(NULL));
    int T = rand() %s;
    file << n << " " << T << endl;
    if (s == 0) {
        // some particular case
        file << "algunaInstanciaParticular" << endl;
    } else {
        // randomized cases
        for (int i = 0; i < n; i++) {
            int x = rand() %s;
            int y = rand() %s;
            file << x << " " << y << endl;
        }
    }
}
