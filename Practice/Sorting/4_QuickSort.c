#include <stdio.h>
#include <stdlib.h>

void dispData(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

int partition(int a[], int min, int max)
{
    int pivot = a[max];
    int i = min - 1, j;

    for (j = min; j < max; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    int temp = a[i];
    a[i] = a[max];
    a[max] = temp;

    return i;
}

void quickSort(int a[], int min, int max)
{
    if (min < max)
    {
        int pivotIndex = partition(a, min, max);
        quickSort(a, min, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, max);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int SIZE = sizeof(a) / sizeof(a[0]);
    int min = 0, max = SIZE - 1;

    printf("\nUnSorted Array\n");
    printf("-------------------------------------------------------------\n");
    dispData(a, SIZE);

    quickSort(a, min, max);

    printf("\nSorted Array\n");
    printf("-------------------------------------------------------------\n");
    dispData(a, SIZE);

    return 0;
}