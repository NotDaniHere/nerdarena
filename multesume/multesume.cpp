#include <bits/stdc++.h>

using namespace std;
ifstream fin("multesume.in");
ofstream fout("multesume.out"); 

int main() {

    int a,b; fin >> a >> b;
    vector<int> A(a), B(b);
    for(int i = 0; i < a; i++) fin >> A[i];
    for(int i = 0; i < b; i++) fin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> Ap, Bp;
    for(int i = 0; i < 2*b; i++) {
        Ap.push_back(A[i]);
        Bp.push_back(B[i]);
    }
    //nu o sa mearga
    return 0;

}
