#include <bits/stdc++.h>

using namespace std;
ifstream fin("sumacifre.in");
ofstream fout("sumacifre.out"); 

int main() {
    int a; fin >> a; unsigned long long suma = 0;
    while(a+1) {
        char c; fin >> noskipws >> c;
        switch(c) {
            case '0'...'9': suma+=int(c) - 48;
        }



        a--;
    }
    fout << suma;
    return 0;

}
