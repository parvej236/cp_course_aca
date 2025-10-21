#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to count: ");
    scanf("%d", &target);

    int low, high, mid;
    int first = -1, last = -1;

    // Hello 
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    
    if (first == -1)
        printf("%d not found in the array.\n", target);
    else
        printf("%d appears %d times.\n", target, (last - first + 1));

    return 0;
}
