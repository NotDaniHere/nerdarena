#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>

using namespace std; //De la un patan, modificat cu GPT

// Functie pentru a calcula CMMD-ul pentru un vector de numere
long long gcd_of_vector(const vector<long long>& nums) {
    return accumulate(nums.begin(), nums.end(), nums[0], std::gcd<long long, long long>);
}

int main() {
    ifstream fin("cmmdc.in");
    ofstream fout("cmmdc.out");

    int T;
    fin >> T;
    int n;
    fin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        fin >> nums[i];
    }

    if (T == 1) {
        // Cerinta 1: CMMD al tuturor numerelor
        long long result = gcd_of_vector(nums);
        fout << result << endl;
    } else if (T == 2) {
        // Cerinta 2: CMMD al n-1 numere
        long long max_gcd = 0;
        for (int i = 0; i < n; ++i) {
            vector<long long> temp = nums;
            temp.erase(temp.begin() + i); // eliminam elementul i
            long long current_gcd = gcd_of_vector(temp);
            max_gcd = max(max_gcd, current_gcd);
        }
        fout << max_gcd << endl;
    } else if (T == 3) {
        // Cerinta 3: CMMD al n-2 numere
        long long max_gcd = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<long long> temp;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        temp.push_back(nums[k]);
                    }
                }
                long long current_gcd = gcd_of_vector(temp);
                max_gcd = max(max_gcd, current_gcd);
            }
        }
        fout << max_gcd << endl;
    }

    fin.close();
    fout.close();
    return 0;
}