#include <bits/stdc++.h>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");


int main() {
    int numar_intervale;
    fin >> numar_intervale;

    vector<pair<int, int>> intervale(numar_intervale);
    for (int i = 0; i < numar_intervale; i++) {
        int minim, maxim;
        fin >> minim >> maxim;
        intervale[i] = {minim, maxim};
    }

    sort(intervale.begin(), intervale.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;
         });

    int numar_frigidere = 0;
    int ultima_temperatura = -999;

    for (const auto& interval : intervale) {
        int limita_stanga = interval.first;
        int limita_dreapta = interval.second;

        if (ultima_temperatura < limita_stanga || ultima_temperatura > limita_dreapta) {
            ultima_temperatura = limita_dreapta;
            numar_frigidere++;
        }
    }

    fout << numar_frigidere << endl;

    return 0;
}
