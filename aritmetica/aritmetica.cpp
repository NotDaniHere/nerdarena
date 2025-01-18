#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("aritmetica.in");
    ofstream fout("aritmetica.out");

    string numberString;
    fin >> numberString;

    int countZeros = 0;
    for (char c : numberString) {
        if (c == '0') {
            countZeros++;
        }
    }

    long long operationCount = 0;
    while (numberString.size() > 1) {
        string nextStepString = "";
        for (int i = 0; i + 1 < (int)numberString.size(); i += 2) {
            int digit1 = (numberString[i] - '0');
            int digit2 = (numberString[i + 1] - '0');
            int sum = digit1 + digit2;
            operationCount++;
            nextStepString += to_string(sum);
        }
        numberString = nextStepString;
    }

    char finalDigit = numberString[0];
    fout << countZeros << endl;
    fout << operationCount << endl;
    fout << finalDigit << endl;

    return 0;
}
