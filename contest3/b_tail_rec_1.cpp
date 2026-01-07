#include <bits/stdc++.h>
using namespace std;

int solve_rec(int n, int rem, int len) {
    if (rem == 0) {
        return len;
    }
    return solve_rec(n, (rem * 10 + 1) % n, len + 1);
}

int main() {
    int n;
    while (cin >> n) {
        int ans = solve_rec(n, 1 % n, 1);
        cout << ans << "\n";
    }
    return 0;
}
