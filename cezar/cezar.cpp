#include <fstream>
using namespace std;
ifstream fin("cezar.in");
ofstream fout("cezar.out");
//FINALLY 100 PT
int main() {
    char c; fin >> c;
    while(!fin.eof()){
      fout << char((c-'a'+1)%26 + 'a');
      fin >> c;
    }


    return 0;
}
