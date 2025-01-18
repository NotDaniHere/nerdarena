#include <bits/stdc++.h>
//Program dedicat lui Tudor, cu ocazia zilei mele de nastere
using namespace std;
ifstream fin("birthday.in");
ofstream fout("birthday.out"); 

int main() {
    for(int i = 0; i < 2000; i++) {
        char c; fin >> noskipws >> c;
        switch(c) {
            case 'T': { 
                fout << 'D';
                break;
            }
            case 't': {
                fout << 'd';
                break; 
            }
            case 'H': {
                fout << 'R';
                break;
            }
            case 'h': {
                fout << 'r';
                break;
            }
            case 'Q': {
                fout << 'A';
                break;
            }
            case 'q': {
                fout << 'a';
                break;
            }
            case 'W': {
                fout << 'G';
                break;
            }
            case 'w': {
                fout << 'g';
                break;
            }
            case 'D': {
                fout << 'N';
                break;
            }
            case 'd': {
                fout << 'n';
                break;
            }
            case 'Y': {
                fout << 'I';
                break;
            }
            case 'y': {
                fout << 'i';
                break;
            }
            case 'U': {
                fout << 'E';
                break;
            }
            case 'u': {
                fout << 'e';
                break;
            }
            case 'b': {
                fout << 'l';
                break;
            }
            case 'B': {
                fout << 'L';
                break;
            }
            case 'j': {
                fout << 't';
                break;
            }
            case 'J': {
                fout << 'T';
                break;
            }
            case 'v': {
                fout << 'f';
                break;
            }
            case 'V': {
                fout << 'F';
                break;
            }
            case 's': {
                fout << 'c';
                break;
            }
            case 'S': {
                fout << 'C';
                break;
            }
            default: {
                fout << c;
                break;
            }

        }      

    
    }
    
    return 0;

    } 
