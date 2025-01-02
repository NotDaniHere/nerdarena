#include <bits/stdc++.h>

using namespace std;
ifstream fin("analiza.in");
ofstream fout("analiza.out"); 
bool isPalindrom(int a) {
    int a1 = a;
    int abba = 0;
    while(a) {
        abba = abba*10 + a%10;
        a/=10;
    }
    return (a1==abba);
}
int main() {
    int a,b; fin >> a >> b;
    if(a == 1) {
        int size = 0, max_size = 0;
        for(int i = 0; i < b; i++) {
            int l; fin >> l; 
            if(isPalindrom(l)) {
                size++;
            } else { 
                size = 0;
            }
            max_size = max(max_size, size);
        }
        fout << max_size;
    }
    

    return 0;

}
