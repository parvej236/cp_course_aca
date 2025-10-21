#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int uniqueVals[100];
    int freq[100];
    int uniqCount = 0;

    // Count frequency manually
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < uniqCount; j++) {
            if (arr[i] == uniqueVals[j]) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            uniqueVals[uniqCount] = arr[i];
            freq[uniqCount] = 1;
            uniqCount++;
        } else {
            freq[found]++;
        }
    }

    // Manual sorting by frequency ↓ then value ↑ (bubble sort)
    for (int i = 0; i < uniqCount - 1; i++) {
        for (int j = 0; j < uniqCount - i - 1; j++) {
            if (freq[j] < freq[j + 1] || (freq[j] == freq[j + 1] && uniqueVals[j] > uniqueVals[j + 1])) {
                int temp = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp;

                int temp2 = uniqueVals[j];
                uniqueVals[j] = uniqueVals[j + 1];
                uniqueVals[j + 1] = temp2;
            }
        }
    }

    // Print final sorted array
    for (int i = 0; i < uniqCount; i++) {
        for (int j = 0; j < freq[i]; j++) {
            cout << uniqueVals[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
