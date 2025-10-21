#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5,3,3,5,4};
    map<int, int> freq;

    // Count frequencies
    for (int x : arr)
        freq[x]++;

    // Custom sort using lambda
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (freq[a] != freq[b])
            return freq[a] > freq[b]; // higher frequency first
        return a < b;                 // if same frequency, smaller value first
    });

    // Output result
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
