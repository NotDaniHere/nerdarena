#include <bits/stdc++.h>
using namespace std;

// We use static-size arrays to ensure we stay within memory limits.
// Each array [N+1][N+1] of int consumes (N+1)*(N+1)*4 bytes.
// For N=1000, that's about 4 MB per array, well under 16 MB total.

static const int MAXN = 1000;

// We store matrix A and prefix sums in global (or static) arrays.
int A[MAXN+1][MAXN+1];
int pref[MAXN+1][MAXN+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;  // K up to 1e6, but sums can be up to 1e9
    cin >> N >> K;

    // Read the matrix (1-based indexing).
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }

    // Build prefix sums, using int since total can be up to 1e9 (still fits in signed 32-bit?):
    // Actually 1e9 fits in 32-bit int, but be mindful that sums can be EXACT 1e9. It's safe.
    // pref[i][j] = sum of A[x][y] for 1 <= x <= i, 1 <= y <= j.
    for(int i = 1; i <= N; i++){
        int rowSum = 0;
        for(int j = 1; j <= N; j++){
            rowSum += A[i][j];
            pref[i][j] = pref[i-1][j] + rowSum;
        }
    }

    // Helper lambda to get sum of sub-square with corners (r1,c1) and (r2,c2) inclusive.
    auto getSum = [&](int r1, int c1, int r2, int c2){
        // 1 <= r1 <= r2 <= N, 1 <= c1 <= c2 <= N
        int s = pref[r2][c2];
        s -= pref[r1-1][c2];
        s -= pref[r2][c1-1];
        s += pref[r1-1][c1-1];
        return s;
    };

    long long ans = 0; // final answer: how many (i,j) centers can yield sum == K

    // Check each cell (i,j) as center
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // maximum radius so that sub-square is fully inside [1..N]
            int maxR = min({ i, j, N - i + 1, N - j + 1 });
            // We'll do binary search on r in [1..maxR]
            int left = 1, right = maxR;
            bool found = false;
            while(left <= right){
                int mid = (left + right) / 2;

                int r1 = i - (mid - 1);
                int c1 = j - (mid - 1);
                int r2 = i + (mid - 1);
                int c2 = j + (mid - 1);

                long long s = getSum(r1, c1, r2, c2);

                if(s == K){
                    ans++;
                    found = true;
                    break; // no need to check other radii for this center
                } 
                else if(s < K){
                    // sum < K => need a larger radius to (possibly) reach K
                    left = mid + 1;
                } 
                else {
                    // sum > K => try smaller radius
                    right = mid - 1;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
