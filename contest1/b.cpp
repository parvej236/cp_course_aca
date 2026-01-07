#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        if (!(cin >> n)) return 0; // EOF or input error
        if (n == 0) break;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long inv = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) ++inv;
            }
        }

        cout << inv << "\n";
    }
    return 0;
}
