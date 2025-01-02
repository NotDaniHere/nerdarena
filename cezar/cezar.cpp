#include <bits/stdc++.h>
using namespace std;
ifstream fin("cezar.in");
ofstream fout("cezar.out"); 
//N-am idee cum sa dai pe 100pt
int main() {
    string S; getline(fin, S);
    for(char c: S) {
      fout << char((c-'a'+1)%26 + 'a');
      fin >> c;	
    }

	
    return 0;	
}