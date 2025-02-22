#include <bits/stdc++.h>

using namespace std;
ifstream fin("schi.in");
ofstream fout("schi.out"); 

int main() {
    int a; fin >> a;
    vector<int> puncte(a);
    unordered_map<int, vector<int>> prikoale;
    int maxu = 0;
    for(int i = 0; i < a; i++) {
        fin >> puncte[i];
        maxu = max(maxu, puncte[i]);
        prikoale[puncte[i]].push_back(i+1);
        prikoale[puncte[i]].push_back(maxu);
        
    }
    int b; fin >> b;
    vector<int> intrebari(b);
    for(int i = 0; i < b; i++) fin >> intrebari[i];


    for(int i : intrebari) {
        if(prikoale.count(i)) {
            int primu = prikoale[i][0];
            if(i < prikoale[i][1]) fout << 0 << ' ';
            else {
                int interval = 1;
                for(int i = primu; i < puncte.size(); i++) {
                    cout << puncte[primu-1] << ' ' << puncte[i] << endl; 
                    if(puncte[primu-1] >= puncte[i]) interval++;
                    else break;
                }
                cout << endl;
                fout << interval << ' ';
            }
        }
        else {
            fout << 0 << ' ';
        }
    }
    
    return 0;

}
