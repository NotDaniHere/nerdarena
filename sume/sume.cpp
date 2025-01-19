#include <bits/stdc++.h>

using namespace std;
ifstream fin("sume.in");
ofstream fout("sume.out"); 

int main() {

    int a,b; fin >> a >> b;
    vector<int> numere;
    for(int i = 0; i < a; i++) {
        int c; fin >> c;
        numere.push_back(c);
    }
    sort(numere.begin(), numere.end(), greater<>());

    long long sumapana = 0, sumadupa = 0;
    int counter = 0;
    if(numere[0] < 0) sumapana += numere[0]; 
    for(int i : numere) {
        if (counter < b && i > 0) sumapana+=i;
        if (counter < b || i > 0) sumadupa+=i; 
        counter ++;
    }
    fout << sumadupa << endl << sumapana << endl;
    return 0;
}
