#include <stdio.h>

int main()
{
    int n = 6;
    int ara[] = {3,6,9,12,15,18};
    int key = 9;
    int found = 0;

    int low = 0;
    int high = n - 1;
    int mid;


    while (low <= high)
    {
        mid = (high + low) / 2;
        if (ara[mid] == key)
        {
            printf("find in index: %d\n", mid+1);
            found=1;
            break;
        }
        else if (key > ara[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        printf("-1\n");
    }

    return 0;
}