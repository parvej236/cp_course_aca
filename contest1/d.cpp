#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(const vector<long long>& pos, int E, long long dist) {
    int count = 1; 
    long long last = pos[0];

    for (int i = 1; i < (int)pos.size(); i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
            if (count == E) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<long long> pos(N);
        for (int i = 0; i < N; i++) cin >> pos[i];

        sort(pos.begin(), pos.end());

        long long low = 0;
        long long high = pos[N - 1] - pos[0];
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPlace(pos, E, mid)) {
                ans = mid;
                low = mid + 1;   
            } else {
                high = mid - 1; 
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
