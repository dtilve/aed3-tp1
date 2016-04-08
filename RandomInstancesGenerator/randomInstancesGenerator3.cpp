#include "randomInstancesGenerator3.h"

int main() {
    int n, s;
    cout << "Ingrese 0 si desea generar una instancia con el peor caso, "
    << "1 para el mejor caso y cualquier otro número para un caso completamente aleatorio" << endl;
    cin >> s;
    cout << "Ingrese el tamaño de la entrada a ser generada." << endl;
    cin >> n;
    ofstream file;
    string fileName = "instancia" + to_string(n) + ".txt";
    file.open(fileName, fstream::out);
    randomInstanceGenerator(s, n, file);
    cout << "La instancia fue generada con éxito bajo el nombre instancia"+to_string(n)+".txt" << endl;;
    file.close();
    return 0;
}

void randomInstanceGenerator(int s, int n, ofstream &file) {
    // particular cases
    srand(time(NULL));
    file << n << endl;
    if (s == 0) {
        // worst case scenario - completly unaligned
        for (int i = 0; i < n; i++) {
            int x = i;
            int y = pow(2,x);
            file << to_string(x) << " " << to_string(y) << endl;
        }
    } else if (s == 1) {
        // best case scenario - aligned
        int y = 1;
        for (int i = 0; i < n; i++) {
            int x = i;
            file << to_string(x) << " " << to_string(y) << endl;
        }
    } else {
        // random case scenario
        for (int i = 0; i < n; i++) {
            int x = rand() %1000;
            int y = rand() %1000;
            file << to_string(x) << " " << to_string(y) << endl;
        }
    }
}
