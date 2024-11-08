#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[], int SIZE, int key)
{
    int index = -1;
    int min = 0, mid, max = SIZE - 1;

    while (min <= max)
    {
        mid = (min + max) / 2;
        if (a[mid] == key)
        {
            index = mid;
            break;
        }
        else if (key > a[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    return index;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int SIZE = sizeof(a) / sizeof(int);
    int index = -1, key;

    printf("\nEnter the key : ");
    scanf("%d", &key);

    index = binarySearch(a, SIZE, key);

    if (index == -1)
    {
        printf("\n%d key is not found", key);
    }
    else
    {
        printf("%d key is found at %d index", key, index);
    }

    return 0;
}