#include <stdio.h>
#include <stdlib.h>

void dispData(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void merge(int arr[], int min, int mid, int max)
{
    int SIZE1 = mid - min + 1;
    int SIZE2 = max - mid;

    int a[SIZE1];
    int b[SIZE2];

    for (int i = 0; i < SIZE1; i++)
    {
        a[i] = arr[min + i];
    }

    for (int i = 0; i < SIZE2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = min;
    while (i < SIZE1 && j < SIZE2)
    {
        if (a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < SIZE1)
    {
        arr[k++] = a[i++];
    }
    while (j < SIZE2)
    {
        arr[k++] = a[j++];
    }
}

void mergeSort(int a[], int min, int max)
{
    if (min < max)
    {
        int mid = (min + max) / 2;
        mergeSort(a, min, mid);
        mergeSort(a, mid + 1, max);
        merge(a, min, mid, max);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int SIZE = sizeof(a) / sizeof(int);
    int min = 0, max = SIZE - 1;

    printf("\nUnSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    mergeSort(a, min, max);

    printf("\nSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    return 0;
}