#include <bits/stdc++.h>
using namespace std;
ifstream fin("fib.in");
ofstream fout("fib.out");

vector<int> sums(vector<int> a, vector<int> b) {
    while(a.size() < b.size()) a.insert(a.begin(), 0);
    while(b.size() < a.size()) b.insert(b.begin(), 0);
    vector<int> result;
    int swap = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = a[i] + b[i] + swap;
        swap = sum / 10;
        result.insert(result.begin(), sum % 10);
    }
    if (swap)
        result.insert(result.begin(), swap);
    
    return result;
}
string sigmify(vector<int>& v) {
    string s;
    for (int digit : v) {
        s.push_back('0' + digit);
    }
    return s;
}

int main() {
    int a; fin >> a;
    vector<int> fibonacci = {1};
    vector<int> last_number = {0};
    vector<int> temp;
    
    for(int i = 1; i != a; i++) {
        temp = fibonacci;
        fibonacci = sums(fibonacci, last_number);
        last_number = temp;
    }
    
    fout << sigmify(fibonacci);
    return 0;
}
