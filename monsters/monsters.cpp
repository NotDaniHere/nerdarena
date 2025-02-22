#include <bits/stdc++.h>
using namespace std;
ifstream fin("monsters.in");
ofstream fout("monsters.out"); 
int main() {
    string s; fin >> s;
    unsigned long long suma = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        int a; a = int(s[i]) - '0';
        if(a!=0) suma+=pow(2, s.size()- i - 1);
    }
    fout << suma;
    return 0;

}
