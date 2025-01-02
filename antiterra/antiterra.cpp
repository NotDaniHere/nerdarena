#include <bits/stdc++.h>

using namespace std;

ifstream f("antiterra.in");
ofstream p("antiterra.out");
//ty chatgpt pentru full puncte

int main() {
    int sum = 0;            // Suma totală
    int currentNumber = 0;  // Numărul curent citit
    char ch;                // Caracterul curent
    int sign = 1;           // Semnul curent (implicit pozitiv)

    while (f >> noskipws >> ch) { // Citim caracter cu caracter
        if (isdigit(ch)) {
            // Construim numărul pe baza cifrelor consecutive
            currentNumber = currentNumber * 10 + (ch - '0');
        } else if (ch == '+' || ch == '-') {
            // Dacă întâlnim un semn, acesta aparține numărului curent
            sign = (ch == '+') ? 1 : -1;
        } else if (ch == ' ' || ch == '\n') {
            // La întâlnirea unui spațiu sau sfârșit de linie, procesăm numărul
            sum += currentNumber * sign;
            currentNumber = 0; // Resetăm numărul curent
            sign = 1;          // Resetăm semnul implicit
        }
    }

    p << sum; // Scriem suma totală
    return 0;
}
