#include <bits/stdc++.h>

using namespace std;
ifstream fin("cautare.in");
ofstream fout("cautare.out"); 
int main() {
    int m,n; fin >> m >> n;
    int counter = 0;
    char mare[m][m]; char mic[n][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            fin >> mare[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fin >> mic[i][j];
        }
    }
    for(int i = 0; i < m*m; i++) {
        if(mare[i/m][i%m] == mic[0][0] && (i%m <= m-n) && (i/m <= m-n)) {
            bool running = true;
            for(int j = i/m; j < i/m+n && running; j++) {
                for(int l = i%m; l < i%m+n && running; l++) {
                    if(mare[j][l] == mic[j - (i/m)][l - (i%m)]) running = true;
                    else running = false;
                }
            }
            if(running) counter++;
        }
    }
    fout << counter << endl;



    return 0;

}
