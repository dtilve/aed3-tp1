#include <randomInstancesGenerator2.h>

int main() {
    int n;
    cout << "Ingrese el tamaño de la entrada a ser generada." << endl;
    cin >> n;
    ofstream file;
    string fileName = "instancia" + to_string(n) + ".txt";
    file.open(fileName, fstream::out);
    randomInstancePrinter(n, file);
    cout << "La instancia fue generada con éxito bajo el nombre instancia"+to_string(n)+".txt" << endl;;
    file.close();
    return 0;
}

void randomInstancePrinter(int n, ofstream &file) {
    srand(time(NULL));
    int T = rand() %150;
    file << n << " " << T << endl;

    positionVector_t v = randomInstanceGenerator(n);

    for (int i = 0; i < n; i++) {
        file << v[i].first << " " << v[i].second << endl;
    }
}

positionVector_t randomInstanceGenerator(int n) {
    vector<int> v = randomVectorGenerator(n);
    vector<int> w = randomVectorGenerator(n);
    v = sort(v, n);
    w = sort(w, n);
    return pairGenerator(n, v, w);
}

positionVector_t pairGenerator(int n, vector<int> v, vector<int> w) {
	pair<int,int> posicion;
	positionVector_t container;
	for(int i = 0; i < n ; i++) {
		posicion = make_pair(v[n-1-i], w[i]);
		container.push_back(posicion);
	}
	return container;
}

vector<int> randomVectorGenerator(int n) {
	vector<int> v;
	int i = 0;
    int j;
	while(i < n) {
		j = rand() % 100;
		if(!in(j, v, i)) {
			v.push_back(j);
			i++;
		}
	}
	return v;
}

vector<int> sort(vector<int> v, int n) {
	int aux = 0;
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < (n-1); i++) {
			if(v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
	}
	return v;
}

bool in (int j, vector<int> v, int n) {
	bool b = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == j) {
		   b = true;
		}
	}
	return b;
}
