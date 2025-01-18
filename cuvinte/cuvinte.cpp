#include <bits/stdc++.h>

using namespace std;
ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out"); 

int main() {

    string S; getline(fin, S);
    int words = 1;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == ' ' || S[i] == '.' || S[i]==',') {
            words++; i++;
        }
        while(S[i] == ' ' || S[i] == '.' || S[i] == ',') i++;
    }
    if(S == "") words = 0;
    fout << words;
    return 0;

}
