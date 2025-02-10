#include <bits/stdc++.h>
using namespace std;
ifstream fin("cuvant.txt");
#define cin fin
int main() {

    int fr[256] = {};
    string S; cin >> S;
    for(char s: S) {
        fr[s]++;
    }
    int minim = fr[S[0]]; int maxim = 0;
    for(int i = 'a'; i <= 'z'; i++) {
        if(fr[i] < 100 && count(S.begin(), S.end(), char(i))) {
            cout << char(i) << ' ' << fr[i] << '\n'; 
            minim = min(fr[i], minim);
            maxim = max(fr[i], maxim);
        }
    }
    if(minim == maxim) cout << "Da \n";
    else cout << "Nu \n";
    return 0;

}
