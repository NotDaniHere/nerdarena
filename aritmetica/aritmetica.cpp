#include <bits/stdc++.h>

using namespace std;
ifstream fin("aritmetica.in");
ofstream fout("aritmetica.out"); 

int main() {

    string S; getline(fin, S);
    vector<int> sume;
    int zeroCount = 0; int operationCount = 0;
    for(char c : S) {
        if(c == '0') zeroCount++;
    }
    while(S.size() != 1) {
    if(S.size()%2) S.erase(S.size()-1);
    for(int i = 0; i < S.size(); i+=2) {
        sume.push_back(int(S[i] - '0') + int(S[i+1] - '0'));
        operationCount++;
    }
    S = "";
    for(int i : sume) {
        if(i > 9) {
            S = S + char(i/10 + '0');
            S = S + char(i%10 + '0');
        }
        else S += char(i + '0');
    }
    sume = {};
    
    }
    fout << zeroCount << endl << operationCount << endl << S;
    
    return 0;

}
