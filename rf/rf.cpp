#include <bits/stdc++.h>

using namespace std;
ifstream fin("rucsacfr.in");
ofstream fout("rucsacfr.out"); 


int main() {
    int N, K; fin >> N >> K;
    vector<vector<double>> WORKING = {};
    for(int i = 0; i < N; i++) {
        double g, p; fin >> g >> p;
        WORKING.push_back({p/g, g, p});
    }
    sort(WORKING.begin(), WORKING.end(), greater<>());
    double cost = 0, weight = 0;
    int i = 0;
    while(weight != K && i < N) {
        if(K-weight >= WORKING[i][1]) {
            weight += WORKING[i][1];
            cost += WORKING[i][2];
            
        } else {
            cost += WORKING[i][0] * (K-weight);
            weight = K;
        }
        i++;
    }
    fout << fixed << setprecision(2) << 1.000*cost;
    return 0;

}
