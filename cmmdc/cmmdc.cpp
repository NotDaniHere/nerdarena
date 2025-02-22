#include <bits/stdc++.h>
using namespace std;

ifstream f("cmmdc.in");
ofstream p("cmmdc.out");

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int T;
    f >> T;

    int n;
    f >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        f >> a[i];
    }

    if (T == 1) {
        long long result = a[0];
        for (int i = 1; i < n; ++i) {
            result = gcd(result, a[i]);
            if (result == 1) break;
        }
        p << result;
    } else if (T == 2) {
        vector<long long> prefix(n), suffix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = gcd(prefix[i - 1], a[i]);
        }
        suffix[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = gcd(suffix[i + 1], a[i]);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long cmmdc_n1 = (i == 0) ? suffix[1] : (i == n - 1 ? prefix[n - 2] : gcd(prefix[i - 1], suffix[i + 1]));
            result = max(result, cmmdc_n1);
        }
        p << result;
    } else if (T == 3) {
        vector<long long> prefix(n), suffix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = gcd(prefix[i - 1], a[i]);
        }
        suffix[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = gcd(suffix[i + 1], a[i]);
        }

        long long result = 0;
        for (int i = 1; i < n - 1; ++i) {
            long long cmmdc_n2 = gcd(prefix[i - 1], suffix[i + 1]);
            result = max(result, cmmdc_n2);
        }
        p << result;
    }

    return 0;
}
