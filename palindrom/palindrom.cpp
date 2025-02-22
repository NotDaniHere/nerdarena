#include <bits/stdc++.h>
using namespace std; 

bool isPalindrom(int a, int b) {
    string S = "";
    if(a==0) S="0";
    else {
        while(a) {
            S = char(a%b + '0') + S;
            a/=b;
        }
    }
    string s;
    for(char c: S) {
        s=c+s;
    }
    return S == s;
}

int main() {
    int a, b; cin >> a >> b;
    for(int i = b; i <= a; i++) {
        if(isPalindrom(i, b)) cout << i << ' ';
    }
    return 0;
}
