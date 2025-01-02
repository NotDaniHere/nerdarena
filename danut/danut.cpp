#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
int main() {
	ifstream fin("danut.in");
    ofstream fout("danut.out");
    
    int n;
    fin >> n;
 
    if (n < 1 || n > 100) {
        fout << "Eroare" << endl;
        return 1;
    }
 
    int min_suma = 2*n;
    int caz_rand = 1, caz_col = n;
    int min_d = 2*n;
 
 
    for (int rand = 1; rand <= sqrt(n); ++rand) {
        int col = (n + rand - 1) / rand;
        int sum = rand + col;
        int d = col * rand - n;
 
 
        if (sum < min_suma || (sum == min_suma && d < min_d)) {
            min_suma = sum;
            caz_rand = rand;
            caz_col = col;
            min_d = d;
        }
    }
 
    fout << caz_rand << " " << caz_col << endl;
 
    return 0;
}