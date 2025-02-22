#include <bits/stdc++.h>

using namespace std;
ifstream fin("jbird.in");
ofstream fout("jbird.out"); 

int main() {
    int a,b,c; fin >> a >> b >> c;
    int size_i = 0;
    vector<int> inaltimi;
    vector<int> pozitii;
    for(int i = 0; i < a; i++) {
        int d; fin >> d;
        inaltimi.push_back(d);
        size_i++;
    }
    for(int i = 0; i < b; i++) {
        int e; fin >> e;
        pozitii.push_back(e);
    }
    for(int i : pozitii) {
        i--;
        int index_min = max(0, i-c);
        int index_max = min(i+c, size_i);
        int maxim = 0;
        for(int j = index_min; j <= index_max; j++) {
            maxim = max(maxim, inaltimi[j]);
        }
        fout << maxim << endl;
    }
    return 0;

}
