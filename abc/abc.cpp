#include <bits/stdc++.h>
	
 
	
using namespace std;
	
ifstream fin("bratara.in");
	
ofstream fout("bratara.out"); 
	
 
	
int getLastDigits(int a) {
	
    return a%100;
	
}
	
int getFirstDigits(int a) {
	
    int d1 = 0, d2;
	
    while(a) {d2 = d1; d1 = a; a/=10;}
	
    return d2;
	
}
	
 
	
 
	
 
	
int main() {
	
    int a, b; fin >> a >> b;
	
    int last_number = 0;
	
    int secv_counter = 0;
	
    for(int i = 0; i <= b; i++) {
	
        int c; fin >> c;
	
        if(getLastDigits(last_number) == getFirstDigits(c)) {
	
            while(getLastDigits(last_number) == getFirstDigits(c)) {
	
                 last_number = c; fin >> c; i++;
	
            }
	
            secv_counter++; 
	
        }
	
        last_number = c;
	
    }
	
    fout << secv_counter;
	
 
	
 
	
 
	
 
	
 
	
 
	
 
	
    return 0;
	
 
	
}