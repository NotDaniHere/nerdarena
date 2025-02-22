#include <bits/stdc++.h>
using namespace std;
ifstream fin("faraon.in");
ofstream fout("faraon.out");

int main() {
    int a, b;
    fin >> a >> b;
    vector<int> loturi(a), piramide(b);
    
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < a; i++) {
        fin >> loturi[i];
        indices[loturi[i]].push_back(i + 1);
    }
    for (int i = 0; i < b; i++)
        fin >> piramide[i];
    
    for (int val : piramide) {
        if (indices.count(val)) {
            for (int index : indices[val])
                fout << index << " ";
        } else {
            fout << 0;
        }
        fout << "\n";
    }
    return 0;
}
