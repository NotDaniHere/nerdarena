#include <bits/stdc++.h>

using namespace std;
ifstream fin("bas.in");
ofstream fout("bas.out"); 

int main() {

    int a,b,c; fin >> a >> b >> c;
    if(a == 1) {
        vector<int> numere;
        for(int i = 0; i < b; i++) {
            int d; fin >> d;
            numere.push_back(d);
        }
        for(int i = 0; i < c; i++) {
            int d; fin >> d;
            bool test = true;
            for(auto k : numere) {
                if(k%d) {test=false; break;}
            }
            fout << test << '\n';
        }
        
    }
    return 0;

}
