#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            result = mid;
            high = mid - 1; // search left side
        } else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            result = mid;
            low = mid + 1; // search right side
        } else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}

int countOccurrences(int arr[], int n, int x) {
    int first = firstOccurrence(arr, n, x);
    if (first == -1)
        return 0; // not found
    int last = lastOccurrence(arr, n, x);
    return last - first + 1;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << "Element " << x << " occurs " << countOccurrences(arr, n, x) << " times." << endl;
    return 0;
}
