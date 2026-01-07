#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

// fast recursive power: computes (a^e) % MOD
int64 modpow(int64 a, int64 e) {
    if (e == 0) {
        return 1;
    }
    int64 half = modpow(a, e / 2);
    int64 result = (half * half) % MOD;
    if (e % 2 == 1) {
        result = (result * a) % MOD;
    }
    return result;
}

int main() {

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long N;
        cin >> N;

        int64 p = modpow(2, N - 1);      // recursive exponentiation
        int64 ans = ( (N % MOD) * p ) % MOD;

        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
