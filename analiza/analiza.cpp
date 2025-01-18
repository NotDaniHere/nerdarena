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
    } else {
        vector<int> lista;
        set<int> numere;
        for(int i = 0; i <= b; i++) {
            int c; fin >> c; 
            lista.push_back(c);
            numere.insert(c);
        }
        int max1, max2;
        max1 = 0; max2 = 0;
        for(int i : numere) {
            int a = count(lista.begin(), lista.end(), i);
            if(max1 < max(a, max1)) {
                max2 = max1;
                max1 = max(a,max1);
            }
        }
        fout << max2;

        
    }
    

    return 0;

}
