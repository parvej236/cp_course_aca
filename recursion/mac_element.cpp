#include<bits/stdc++.h>
using namespace std;

int max_element(int arr[], int n, int idx, int max) {
    if(idx == n) {
        return max;
    }
    if(arr[idx] > max) {
        max = arr[idx];
    }
    return max_element(arr, n, idx + 1, max);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = max_element(arr, n, 0, 0);
    cout << "Maximum element is: " << max << endl;
    return 0;
}