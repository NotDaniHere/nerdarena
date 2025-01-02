#include <bits/stdc++.h>
using namespace std;
ifstream fin("sumadiv.in");
ofstream fout("sumadiv.out"); 
unsigned int sumad(unsigned int a, unsigned int b, unsigned int suma) {
    if (b * b > a) return suma;
    if (a % b == 0) {
        suma += b;
        if (b != a / b) suma += a / b; 
    }
    return sumad(a, b + 1, suma);
}
int main() {
    unsigned int a; fin >> a;
    fout << sumad(a, 1, 0);
    return 0;
}