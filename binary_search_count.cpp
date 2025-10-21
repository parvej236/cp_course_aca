#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    int low = 0, high = n - 1;
    int first = -1, last = -1;

    // Find first occurrence (binary search)
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // continue left
        } else if (x > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Find last occurrence (binary search)
    low = 0;
    high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // continue right
        } else if ( x > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (first == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element " << x << " occurs " << (last - first + 1) << " times." << endl;

    return 0;
}
