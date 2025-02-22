#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a, b; cin >> a >> b;
    if(!a && !b) cout << "Cel mai mic divizor comun nu exista" << endl;
    else if (!a || !b) {
        int r;
        if(!a) r = b; else r = a;
        cout << "Cel mai mic divizor comun este " << r << endl;
    }
    else {
        if(b) {
            int r = a%b;
            while(r) {a=b; b=r; r=a%b;}
            cout << "cmmdc: " << b << endl;
        }
    }



    return 0;
}