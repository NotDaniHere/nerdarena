#include <bits/stdc++.h>

using namespace std;
ifstream fin("concurs.in");
ofstream fout("concurs.out"); 

int main() {

    int a,b; fin >> a >> b;
    int a1 = a/100, a2 = a/10 - a1*10;
    int counter1 = 0, counter2 = 0;
    bool l = false;
    for(int i = 0; i < b; i++) {
        int c; fin >> c;
        int c1 = c/100; int c2 = c/10 - c1*10;
        if(a == c) l = true;
        if(a1 == c1) {
            counter1++;
            if(a2 == c2) counter2++;
        }

        
    }
    if(l) fout << "DA" << endl;
    else fout << "NU" << endl;
    fout << counter1 << endl << counter2;

    return 0;

}
