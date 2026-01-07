#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int total = 0;

    for (int i = 0; i < n; i += 2) {
        total += a[i+1] - a[i];
    }

    cout << total << "\n";

    return 0;
}
