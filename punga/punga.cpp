#include <bits/stdc++.h>
using namespace std;

// Funcție care returnează perechea (W, H) pentru un K dat
pair<long long, long long> solveOne(long long K) {
    // variabile în care reținem cea mai bună soluție
    long long bestW = 1, bestH = K; // o soluție validă trivially e W=1, H=K
    long long bestSum = bestW + bestH;
    long long bestVol = bestW * bestH;

    // O limită rezonabilă până la care iterăm W:
    // fie până la sqrt(K) cu un mic plus.
    long long lim = (long long) floor( sqrt((long double)K ) ) + 2;

    // parcurgem W de la 1 până la min(K, lim) (ca siguranță)
    for (long long W = 1; W <= lim && W <= K; W++) {
        // H minim care satisface W*H >= K
        long long H = (K + W - 1) / W;  // echivalent cu ceil(K/W)

        if (H < W) {
            // nu respectă condiția H >= W
            continue;
        }

        // acum avem un candidat valid
        long long suma = W + H;
        long long vol  = W * H;

        // comparăm cu valorile minime de până acum
        if (suma < bestSum) {
            // am găsit o sumă mai mică -> direct actualizăm
            bestSum = suma;
            bestVol = vol;
            bestW = W;
            bestH = H;
        }
        else if (suma == bestSum && vol < bestVol) {
            // aceeași sumă, dar volum mai mic -> actualizăm
            bestVol = vol;
            bestW = W;
            bestH = H;
        }
    }

    return {bestW, bestH};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> K(T);
    for(int i = 0; i < T; i++){
        cin >> K[i];
    }

    // pentru fiecare K[i], determinăm dimensiunile pungii
    for(int i = 0; i < T; i++){
        auto sol = solveOne(K[i]);
        long long W = sol.first;
        long long H = sol.second;
        cout << W << " " << H << "\n";
    }

    return 0;
}
