#include <bits/stdc++.h>
using namespace std;
ifstream fin("alfanumeric.in");
ofstream fout("alfanumeric.out");
int suma;
int main() {
    int a; fin >> a;
    char c;
    for(int i = 0; i < 2*a; i++) {
        fin >> noskipws >> c;
        switch(c) {
            case 'a'...'z': {
                fout << char(c-32);
                break;
            }
            case 'A'...'Z': {
                fout << c;
                break;
            }
            case '0'...'9': {
                suma+=c-48;
                break;
            }
        }
    }
    fout << '\n' << suma;
    return 0;
}