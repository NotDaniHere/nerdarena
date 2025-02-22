#include <bits/stdc++.h>
using namespace std;
ifstream fin("bancnote.in");
ofstream fout("bancnote.out"); 
int main() {
    int n, s; fin >> s >> n;
    vector<int> bancnote;
    for(int i = 0; i < n; i++) {
        int b; fin >> b;
        bancnote.push_back(b);
    }
    sort(bancnote.begin(), bancnote.end(), greater<>());
    int suma = 0; int num_minim = 0; int iterator = 0;
    while(suma != s) {
        if(suma<s) {suma+=bancnote[iterator]; num_minim++;}
        else if(suma>s) {suma-=bancnote[iterator]; num_minim--; iterator++;}
    }
    fout << num_minim;
    return 0; 
}
