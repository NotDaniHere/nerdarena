#include <iostream>
#include <fstream>
#include <vector>
//ChatGPT ca n-am idee cum sa fac problema asta normal
using namespace std;
 
vector<bool> sieve_of_eratosthenes(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
 
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }
 
    return is_prime;
}
 
int main() {
    ifstream infile("prime.in");
    int x, N;
    infile >> x >> N;
    infile.close();

    const int max_limit = 3000000;
 
    vector<bool> is_prime = sieve_of_eratosthenes(max_limit);
    vector<int> primes;
 
    for (int i = 2; i <= max_limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    int largest_prime_leq_x = -1;
    for (int prime : primes) {
        if (prime <= x) {
            largest_prime_leq_x = prime;
        } else {
            break;
        }
    }
 
    long long sum_of_n_primes_above_x = 0;
    int count = 0;
    for (int prime : primes) {
        if (prime > x) {
            sum_of_n_primes_above_x += prime;
            count++;
            if (count == N) {
                break;
            }
        }
    }
    ofstream outfile("prime.out");
    outfile << largest_prime_leq_x << endl;
    outfile << sum_of_n_primes_above_x << endl;
    outfile.close();
 
    return 0;
}
