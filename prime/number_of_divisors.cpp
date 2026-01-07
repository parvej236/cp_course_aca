#include <bits/stdc++.h>
using namespace std;

// Step 1: Generate prime numbers up to n using Sieve of Eratosthenes
void sieveOfEratosthenes(int n, bool prime[]) {
    memset(prime, true, sizeof(bool) * (n + 1));
    prime[0] = prime[1] = false; // 0 and 1 are not primes

    for(int p = 2; p * p <= n; p++) {
        if(prime[p]) {
            for(int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

// Step 2: Generate the number of divisors for each number from 1 to n
void generateDivisorsCount(int n, int divisorsCount[]) {
    bool prime[n + 1];
    sieveOfEratosthenes(n, prime);

    for(int i = 1; i <= n; i++)
        divisorsCount[i] = 1; // initialize divisors count

    for(int p = 2; p <= n; p++) {
        if(prime[p]) {
            for(int multiple = p; multiple <= n; multiple += p) {
                int exponent = 0;
                int temp = multiple;
                while(temp % p == 0) {
                    temp /= p;
                    exponent++;
                }
                divisorsCount[multiple] *= (exponent + 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int divisorsCount[n + 1];
    generateDivisorsCount(n, divisorsCount);

    // Print the number of divisors for each number
    for(int i = 1; i <= n; i++)
        cout << i << " -> " << divisorsCount[i] << endl;

    return 0;
}
