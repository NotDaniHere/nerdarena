#include <bits/stdc++.h>
	
 
	
using namespace std;
	
ifstream fin("cifre.in");
	
ofstream fout("cifre.out"); 
	
 
	
int main() {
	
int fun_tracker = 0;
	
    for(short i = 0; i < 3; i++) {
	
        unsigned long long a; fin >> a; unsigned short counter = 0;
	
        int x1, x2;
	
        x1 = a%10; x2 = (a%100 - x1)/10;
	
        a/=100;
	
        while(a) {
	
            if(!(counter%2)) {
	
                if(x1 != a%10) {fun_tracker = fun_tracker*10 + 1; break; }
	
            } else {
	
                if(x2 != a%10) {fun_tracker = fun_tracker*10 + 1; break; }
	
            }
	
            a/=10; counter++;
	
        }
	
        if(a==0) fun_tracker = fun_tracker*10 + 2;
	
        
	
        
	
    }
	
    int stat3 = (fun_tracker %10) - 1; fun_tracker /=10;
	
    int stat2 = (fun_tracker%10) - 1; fun_tracker /= 10;
	
    int stat1 = (fun_tracker%10) - 1; fun_tracker /= 10;
	
    fout << stat1 << " " << stat2 << " " << stat3;
	
    return 0;
	
 
	
}