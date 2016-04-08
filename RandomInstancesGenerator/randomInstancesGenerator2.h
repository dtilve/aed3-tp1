#include <stdio.h>      /* stdin, stdout */
#include <fstream>      /* basic file operations */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <string>
#include <time.h>       /* time */
#include <vector>
#include <utility>
using namespace std;

typedef vector<pair<int, int> > positionVector_t;

// Generates and prints on a new file a random generated instances
void randomInstancePrinter(int n, ofstream &file);
// Generates a vector of randomized pairs
positionVector_t randomInstanceGenerator(int n);
// Generates pairs
positionVector_t pairGenerator(int n, vector<int> v, vector<int> w);
// Generates a vector with randomized numbers with no duplicates
vector<int> randomVectorGenerator(int n);
// Indicates whether the integer j belongs to the vector e of size n
bool in(int j, vector<int> e, int n);
// Sorts the vector of size n
vector<int> sort(vector<int> v, int n);
