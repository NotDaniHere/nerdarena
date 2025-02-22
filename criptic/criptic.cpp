#include <bits/stdc++.h>

using namespace std;

ifstream fin("criptic.in");
ofstream fout("criptic.out");

int baza62(string a) {
    int numaru = 0;
    if (a == "0") return 0;

    int counter = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if ('0' <= a[i] && a[i] <= '9')
            numaru += (a[i] - '0') * pow(62, counter);
        else if ('a' <= a[i] && a[i] <= 'z')
            numaru += (a[i] - 'a' + 10) * pow(62, counter);
        else if ('A' <= a[i] && a[i] <= 'Z')
            numaru += (a[i] - 'A' + 36) * pow(62, counter);
        counter++;
    }

    return numaru;
}

int main() {
    vector<int> litere[3844];
    string a;
    char b;
    while (fin >> a >> b) {
        int index = baza62(a);
        litere[index].push_back(b);
    }

    for (int i = 0; i < 3844; i++) {
        for (int j = litere[i].size() - 1; j >= 0; j--) {
            fout << char(litere[i][j]);
        }
    }

    return 0;
}
