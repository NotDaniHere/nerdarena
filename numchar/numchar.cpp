#include <bits/stdc++.h>

using namespace std;

ifstream fin("numchar.in");
ofstream fout("numchar.out");

int main() {
    char c;
    unsigned int a;
    fin >> a;
    unsigned int digits = 0;
    unsigned int letters = 0;

    for (unsigned int i = 0; i <= a; i++) {
        fin >> noskipws >> c;
        switch (c) {
            case 'a'...'z':
                letters++;
                break;

            case 'A'...'Z':
                letters++;
                break;

            case '0'...'9':
                digits++;
                break;

            default:
                break;
        }
    }
    fout << letters << " " << digits;
    return 0;
}
