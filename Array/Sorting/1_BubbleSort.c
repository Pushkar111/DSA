/*
Bubble Sort
    Best Case: O(n) [(when the array is already sorted)]
    Average Case: O(n^2)
    Worst Case: O(n^2)

 */

#include <stdio.h>
#include <conio.h>
#define SIZE 7

// 55 87 65 43 45 67 89

int a[SIZE];

void scanData()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }
}

void dispData()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void bubbleSort()
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
        dispData(); // print the array after each pass
    }
    printf("\n\nSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData();
}

int main()
{
    scanData();

    printf("\nUnSorted Array\n");
    printf("------------------------------------------------------------------------\n");

    dispData();

    bubbleSort();

    return 0;
}