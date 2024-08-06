/*
Bubble Sort
    Best Case: O(n) [(when the array is already sorted)]
    Average Case: O(n^2)
    Worst Case: O(n^2)

 */

// 55 87 65 43 45 67 89

#include <stdio.h>
#include <conio.h>

void dispData(int a[], int SIZE)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void bubbleSort(int a[], int SIZE)
{
    int i, j, temp;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("\n\nPass: %d => ", i + 1);
        dispData(a, SIZE); // print the array after each pass
    }
    printf("\n\nSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData(a, SIZE);
}

int main()
{
    int a[] = {55, 87, 65, 43, 45, 67, 89};
    int SIZE = sizeof(a) / sizeof(int);

    printf("\nUnSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData(a, SIZE);

    bubbleSort(a, SIZE);

    return 0;
}