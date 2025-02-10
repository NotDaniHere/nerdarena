#include <bits/stdc++.h>
using namespace std;
ifstream fin("bancomat.txt"); 
#define cin fin
#define pb push_back
#define pop pop_back
using ll = long long;
using ull = unsigned long long;
int main() {
    bool instant = true;
    unsigned long long a,b; fin >> a >> b;
    vector<vector<int>> bancomat = {};
    for(int i = 0; i < a; i++) {
        int c,d; cin >> c >> d;
        if(b%c==0)instant=false;
        bancomat.push_back({c,d});
    }
    if(instant) {
        cout << "Suma nu poate fi achitata. Au ramas de achitat " << b << " lei \n";
        return 0;
    }
    sort(bancomat.begin(), bancomat.end(), greater<>());
    ull suma_curenta = 0;
    for(int i = 0; i<bancomat.size(); i++) {
        int current_bancnote = 0;
        while(suma_curenta+bancomat[i][0] <= b && bancomat[i][1] > 0) {
            suma_curenta+=bancomat[i][0];
            current_bancnote++;
            bancomat[i][1]--;
        }
        if(current_bancnote) cout << current_bancnote << ' ' << bancomat[i][0] << ' ' <<  b-suma_curenta << endl;
        if(suma_curenta<b && i == bancomat.size() - 1) break;
    
    }
    if(suma_curenta<b) cout << "Suma nu poate fi achitata." << endl << "Au ramas " << b-suma_curenta << " lei \n";
    else cout << "Suma poate fi achitata. \n";
return 0;
}
