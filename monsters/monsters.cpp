#include <bits/stdc++.h>

using namespace std;
ifstream fin("monsters.in");
ofstream fout("monsters.out"); 

string binarDecimal(const string& binarDec) {
    string result = "0"; 
    for (char digit : binarDec) {
        int carry = (digit!=48);
        for (int i = result.size() - 1; i >= 0; --i) {
            int num = (result[i] - '0') * 2 + carry;
            result[i] = (num % 10) + '0';
            carry = num / 10;
        }
        if (carry) result.insert(result.begin(), carry + '0');
    }
    return result;
}


int main() {
    string S; getline(fin,S);
    string decimal = binarDecimal(S);
    fout << decimal;
    return 0;
}