#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5};
const int n = sizeof(arr) / sizeof(arr[0]);

int sum_normal(int index) {
    if (index == n) {
        return 0;
    }
    return arr[index] + sum_normal(index + 1);
}

int sum_tail(int index, int result) {
    if (index == n) {
        return result;
    }
    return sum_tail(index + 1, result + arr[index]);
}

int main() {
    cout << "normal: " << sum_normal(0) << "\n";
    cout << "tail: " << sum_tail(0, 0) << "\n";

    return 0;
}