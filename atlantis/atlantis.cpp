#include <bits/stdc++.h>

using namespace std;
ifstream fin("atlantis.in");
ofstream fout("atlantis.out"); 

int main() {

    int a,b,c; fin >> a >> b >> c;
    if(a == 1) {
        int counter = 0;
        for(int i = 0; i < b; i++) {
            int d; fin >> d;
            if(d < c) counter++;
        }
        fout << counter;
    } else if (a == 2) {

        vector<pair<int, int>> munti;
        for(int i = 0; i < b; i++) {
            int d; fin >> d;
            munti.push_back({d, i});
        }
        sort(munti.begin(), munti.end());
        for(auto k : munti) {
            fout << k.second+1 << ' ';
        }

    } else {

        vector<pair<int, int>> munti;
        for(int i = 0; i < b; i++) {
            int d; fin >> d;
            munti.push_back({d, i});
        }
        vector<pair<int, int>> preord = munti;
        sort(munti.begin(), munti.end());
        vector<vector<int>> preordine;
        for(int i = 0; i < b; i++) {
            preordine.push_back({munti[i].second, munti[i].first, i});
        }
        sort(preordine.begin(), preordine.end());
        for(auto k : preordine) {
            fout << k[2]+1 << ' ';
        }
    


    }

    return 0;

}
