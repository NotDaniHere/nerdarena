#include <bits/stdc++.h>
using namespace std;
ifstream fin("bancomat.in");
ofstream fout("bancomat.out"); 
int main() {
    unsigned long long a;
    int b; fin >> a >> b;
    for(int i = 0; i < b; i++) {
        int d; fin >> d;
        int l = d/10;
        if(d%10 == 2) {
            a += d/10;
        } else if (d%10 == 3) {
            if(a < l) continue;
            else a -= d/10;
        }
    }
    fout << a;
    return 0;

}
