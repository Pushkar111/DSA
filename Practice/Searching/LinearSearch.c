#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[], int SIZE, int key)
{
    int index = -1;
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] == key)
        {
            index = i;
            break;
        }
    }
    return index;
}

int main()
{
    int a[] = {43, 134, 24, 135, 2, 23};
    int SIZE = sizeof(a) / sizeof(int);
    int index = -1, key;

    printf("Enter the key : ");
    scanf("%d", &key);

    index = linearSearch(a, SIZE, key);

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