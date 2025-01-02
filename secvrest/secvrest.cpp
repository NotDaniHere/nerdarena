#include <bits/stdc++.h>

using namespace std;
ifstream fin("secvrest.in");
ofstream fout("secvrest.out"); 
int main() {
    int a; fin >> a;
    int A[a];
    for(int i = 0; i < a; i++) {
        int b; fin >> b;
        A[i] = b;
    }
    int suma;
    for(int i = 0; i < a; i++) {
        if(A[i] < A[i+1]) {
            suma+=A[i];
        } else {
            if(!(suma%a)) {
                cout << "Suma gasita" << endl;
            }
            suma = 0;
        }
    }


    return 0;

}
