	
#include <bits/stdc++.h>
	
using namespace std;
	
 
	
ifstream fin("bratara.in");
	
ofstream fout("bratara.out");
	// Sigma ChatGPT pentru conditia 2
	
// Funcție pentru a obține ultimele două cifre ale unui număr
	
int getLastDigits(int a) {
	
    return a % 100;
	
}
	
 
	
// Funcția pentru a obține primele două cifre ale unui număr - versiunea utilizată de tine
	
int getFirstDigits(int a) {
	
    int d1 = 0, d2;
	
    while (a) {
	
        d2 = d1;
	
        d1 = a;
	
        a /= 10;
	
    }
	
    return d2;
	
}
	
 
	
int main() {
	
    int a, b;
	
    fin >> a >> b;
	
 
	
    if (a == 1) {
	
        int last_number = 0;
	
        int secv_counter = 0;
	
 
	
        for (int i = 0; i < b; i++) {
	
            int c;
	
            fin >> c;
	
 
	
            if (getLastDigits(last_number) == getFirstDigits(c)) {
	
                while (i < b && getLastDigits(last_number) == getFirstDigits(c)) {
	
                    last_number = c;
	
                    fin >> c;
	
                    i++;
	
                }
	
                secv_counter++;
	
            }
	
 
	
            last_number = c;
	
        }
	
 
	
        fout << secv_counter;
	
 
	
    } else if (a == 2) {
	
        // Cerința 2: Găsim cea mai lungă brățară norocoasă
	
        vector<int> sir(b);
	
        for (int i = 0; i < b; i++) {
	
            fin >> sir[i];
	
        }
	
 
	
        int maxLungime = 0, startMax = -1, endMax = -1;
	
 
	
        int start = 0;
	
        while (start < b) {
	
            int end = start;
	
 
	
            // Extindem secvența cât timp respectă regula
	
            while (end + 1 < b && getLastDigits(sir[end]) == getFirstDigits(sir[end + 1])) {
	
                end++;
	
            }
	
 
	
            // Verificăm dacă este norocoasă (primul și ultimul element respectă regula)
	
            if (getLastDigits(sir[end]) == getFirstDigits(sir[start])) {
	
                int lungime = end - start + 1;
	
                if (lungime > maxLungime) {
	
                    maxLungime = lungime;
	
                    startMax = start + 1; // Indicele începe de la 1
	
                    endMax = end + 1;     // Indicele începe de la 1
	
                }
	
            }
	
 
	
            // Continuăm după finalul secvenței
	
            start = end + 1;
	
        }
	
 
	
        if (maxLungime > 0) {
	
            fout << maxLungime << " " << startMax << " " << endMax;
	
        } else {
	
            fout << -1;
	
        }
	
    }
	
 
	
    return 0;
	
}