#include <bits/stdc++.h>

using namespace std;
ifstream fin("cautare1.in");
ofstream fout("cautare1.out"); 

int main() {
    int a,b; fin >> a >> b;
    vector<int> v;
    for(int i = 0; i < a; i++) {
        int c; fin >> c;
        v.push_back(c);
    }
    for(int i = 0; i < b; i++) {
        int c; fin >> c;
        for(int j = 0; j < a; j++) {
            if(v[j] == c) {fout << j+1 << endl; break;}
            else if(j == a-1) fout << 0 << endl;
        }
    }

    return 0;

}
