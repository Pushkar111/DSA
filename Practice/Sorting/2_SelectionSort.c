#include <stdio.h>
#include <stdlib.h>

void dispData(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void selectionSort(int a[], int SIZE)
{
    int i, j, temp, min;

    for (i = 0; i < SIZE; i++)
    {
        min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int SIZE = sizeof(a) / sizeof(int);

    printf("\nUnSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    selectionSort(a, SIZE);

    printf("\nSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    return 0;
}