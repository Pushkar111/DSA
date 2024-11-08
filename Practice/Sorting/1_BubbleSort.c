#include <stdio.h>
#include <stdlib.h>

void dispData(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void bubbleSort(int a[], int SIZE)
{
    int i, j, temp, ex = 0;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                ex++;
            }
        }
    }
    if (ex == 0)
    {
        printf("\nArray is already sorted\n");
    }
    else
    {
        printf("\nNumber of exchange: %d\n", ex);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int SIZE = sizeof(a) / sizeof(int);

    printf("\nUnSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    bubbleSort(a, SIZE);

    printf("\nSorted Array");
    printf("\n-------------------------------------------------------------\n");
    dispData(a, SIZE);

    return 0;
}