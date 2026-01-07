#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long b, long long p, long long m) {
    if (p == 0) {
        return 1 % m;
    }
    long long half = bigmod(b, p / 2, m);
    long long result = (half * half) % m;
    if (p % 2 == 1) {
        result = (result * (b % m)) % m;
    } 
    return result;
}

int main() {
    long long B, P, M;
    while (cin >> B >> P >> M) {
        cout << bigmod(B, P, M) << "\n";
    }
    return 0;
}
