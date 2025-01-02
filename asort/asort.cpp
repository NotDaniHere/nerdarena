#include <iostream>
#include <fstream>
 //blea hz ce ii codu ista da phd merge
long long calcu (long long k, long long r, long long n, bool d) {
	if (d == 1) {
		if ((k%10)%2 == 0) {
			k=(k-r+n)%n;
		} else {
			k=(k+r+n)%n;
		}
	} else {
		if ((k%10)%2 == 0) {
			k=(k+r+n)%n;
		} else {
			k=(k-r+n)%n;
		}
	}
	if (k == 0) {
		k = n;
	}
	return k;
}
 
long long calc (long long k, long long r, long long n) {
	
	if (r % 2 == 0) {
		k = calcu (k, r, n, false);
	} else {
		k = calcu (k, r, n, true);
	}
	return k;
}
 
using namespace std;
 
int main () {
	ifstream fin("asort.in");
    ofstream fout("asort.out");
 
    long long p, r, n, k, t;
    fin >> p >> n >> r >> k >> t;
    r %= n;
    
    if (r > (n/2)) {
    	r=r-n;
	}
    
    if (p == 1) {
    	t = 0;
    	long long k2 = calc (k, r, n);
    	fout << k2;
	} else  {
		k = 0;
		long long t2 = calcu (t, r, n, true);
		long long p = t2 - 1;		
		long long pred = calc (p, r, n);
		long long s = t2 + 1;
		long long suc = calc (s	, r, n);
		fout << pred << " " << suc;
	}
}