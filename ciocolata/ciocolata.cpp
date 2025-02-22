#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("ciocolata.in");
    ofstream fout("ciocolata.out");

    int C, N;
    fin >> C >> N;

    vector<int> gramaje(N);
    for (int i = 0; i < N; i++) {
        fin >> gramaje[i];
    }

    if (C == 1) {
        // Cerin?a 1: Cel mai frecvent gramaj
        int max_count = 0;
        int result_gramaj = INT_MAX;

        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (gramaje[j] == gramaje[i]) {
                    count++;
                }
            }
            // Verificam daca este cel mai frecvent gramaj
            if (count > max_count || (count == max_count && gramaje[i] < result_gramaj)) {
                max_count = count;
                result_gramaj = gramaje[i];
            }
        }

        fout << result_gramaj << endl;

    } else if (C == 2) {
        // Cerin?a 2: Diferen?a minima
        long long min_difference = LLONG_MAX;

        for (int i = 1; i < N; i++) {
            long long total_irina = 0;
            long long total_mihaela = 0;

            // Irina consuma primele i tablete
            for (int j = 0; j < i; j++) {
                total_irina += gramaje[j];
            }

            // Mihaela consuma ultimele N-i tablete
            for (int j = N - 1; j >= N - (N - i); j--) {
                total_mihaela += gramaje[j];
            }

            // Verificam condi?ia
            if (total_irina >= total_mihaela) {
                long long difference = total_irina - total_mihaela;
                min_difference = min(min_difference, difference);
            }
        }

        fout << min_difference << endl;
    }

    return 0;
}
