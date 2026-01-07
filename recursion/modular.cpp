#include <bits/stdc++.h>
using namespace std;

int big_mod(int x, int n) {
    // x^n (mod 7)
    if (n == 0) {
        return 1;
    }
    int half = big_mod(x, n / 2);
    int result = (half * half) % 7;
    if (n % 2 == 1) {
        result = (result * x) % 7;
    }
    return result;
}

int big_mod_tail(int x, int n, int acc = 1) {
    if (n == 0) return acc;        // base case returns accumulated result
    if (n % 2 == 1)
        return big_mod_tail(x, n - 1, (acc * x) % 7); // multiply accumulator if odd
    else
        return big_mod_tail((x * x) % 7, n / 2, acc); // square x, divide n
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << big_mod(x, n) << "\n";
    cout << big_mod_tail(x, n) << "\n";
    return 0;
}