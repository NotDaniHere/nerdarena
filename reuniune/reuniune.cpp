#include <bits/stdc++.h>
using namespace std;
ifstream fin("reuniune.in");
ofstream fout("reuniune.out"); 
int main() {	
    int a,b,c,d; fin >> a >> b >> c >> d;
    int x, y;
    x = min(a,min(b,min(c,d)));
    y = max(a,max(b,max(c,d)));
    if(c<a && c<b && d<b && d<a) {fout << -1; return 0;}
    if(c > b) fout << -1;
    else fout << x << " " << y;



    return 0;
	
 
	
}