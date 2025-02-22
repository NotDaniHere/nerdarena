#include <bits/stdc++.h>

using namespace std;
ifstream fin("minge.in");
ofstream fout("minge.out"); 

int main() {

    int a,b,c; fin >> a >> b >> c;
    if(a == 1) {
        set<int> copkii;
        for(int i = 0; i < c*2; i++) {
            int d; fin >> d;
            copkii.insert(d);
        }
        fout << b - copkii.size();   
    } else {
        pair<int, int> traseul[b] = {};
        pair<int, int> corect[b] = {};
        int last_player = 0;
        for(int i = 0; i < b; i++) {
            traseul[i] = {0, 0};
        }
        for(int i = 0; i < c; i++) {
            int d,e; fin >> d >> e;
            traseul[e].first = d;
            traseul[e].second = e;
            corect[d].first = d;
            corect[d].second = e;
            last_player = d;
        } 
        while(true) {
            if(traseul[last_player].second == 0) break;
            last_player = traseul[last_player].first;
        }
        fout << last_player << ' ';
        while(true) {
            fout << corect[last_player].second << ' ';
            last_player = corect[last_player].second;
            if(corect[last_player].second == 0) break;
        }
    }
    return 0;

}
