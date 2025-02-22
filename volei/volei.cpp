#include <bits/stdc++.h>
using namespace std;
ifstream fin("volei.in");
ofstream fout("volei.out"); 
int main() {
    int a; fin >> a;
    vector<int> fete;
    for(int i = 0; i < a; i++) {
        int f; fin >> f; fete.push_back(f);
    }
    int b; fin >> b;
    vector<int> baieti;
    for(int i = 0; i < b; i++) {
        int f; fin >> f; baieti.push_back(f);
    }
    sort(baieti.begin(), baieti.end(), greater<>());
    vector<int> al;
    for(int i = 0; i < fete.size(); i++) {
        if(i == fete.size() - 1) al.push_back(max(fete[0], fete[i]));
        else al.push_back(max(fete[i], fete[i+1]));
    }
    int patani = 0;
    vector<int> finalu;
    int counter = 0;
    for(int i : al) {
        finalu.push_back(fete[counter]);
        int minu = 1000;
        for(int j = baieti.size() - 1; j >= 0; j--) {
            if(baieti[j] > i) {
                minu = baieti[j];
                cout << minu << endl;
                patani++;
                baieti[j] = 0;
                finalu.push_back(-minu);
                break;
            }
        }
        counter++;
    }
    fout << patani<< '\n';
    for(int i : finalu) {
        fout << i << ' ';
    }
    
    
    return 0;

}
