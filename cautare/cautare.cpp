#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cautare.in");
    ofstream fout("cautare.out");

    int m, n;
    fin >> m >> n;

    string A[105];
    for (int i = 0; i < m; i++) {
        fin >> A[i];
    }

    string B[105];
    for (int i = 0; i < n; i++) {
        fin >> B[i];
    }

    long long countAppear = 0;
    for (int i = 0; i <= m - n; i++) {
        for (int j = 0; j <= m - n; j++) {
            bool match = true;
            for (int r = 0; r < n && match; r++) {
                for (int c = 0; c < n; c++) {
                    if (A[i + r][j + c] != B[r][c]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) {
                countAppear++;
            }
        }
    }

    fout << countAppear << endl;

    return 0;
}
