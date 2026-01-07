#include <iostream>
using namespace std;

typedef long long ll;

ll cum_sum(ll k, ll m) {
    if (m <= k) {
        return m * (m + 1) / 2;
    } else {
        ll j = m - k;
        return k * (k + 1) / 2 + j * k - j * (j + 1) / 2;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;

        ll total = k * k;
        if (x >= total) {
            cout << 2 * k - 1 << "\n";
            continue;
        }

        ll left = 1, right = 2 * k - 1, ans = 2 * k - 1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll sum = cum_sum(k, mid);
            if (sum >= x) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
