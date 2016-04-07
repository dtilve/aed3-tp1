#include <stdio.h>      /* stdin, stdout */
#include <fstream>      /* basic file operations */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <string>
#include <time.h>       /* time */
using namespace std;

// random tuple generator
void randomInstanceGenerator(int n, ofstream &file);

int main() {
    int n;
    cout << "Ingrese el tamaño de la entrada a ser generada." << endl;
    cin >> n;
    ofstream file;
    string fileName = "instancia" + to_string(n) + ".txt";
    file.open(fileName, fstream::out);
    randomInstanceGenerator(n, file);
    cout << "La instancia fue generada con éxito bajo el nombre instancia"+to_string(n)+".txt" << endl;;
    file.close();
    return 0;
}

void randomInstanceGenerator(int n, ofstream &file) {
    // random seed
    srand(time(NULL));
    int T = rand() %10000;
    file << n << " " << T << endl;
    for (int i = 0; i < n; i++) {
        int x = rand() %1000;
        int y = rand() %1000;
        file << x << " " << y << endl;
    }
}
