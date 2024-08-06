// Use for small amount of Data
/*
insertion sort
    Best Case: O(n) [(when the array is already sorted)]
    Average Case: O(n^2)
    Worst Case: O(n^2)
*/
#include <stdio.h>
#include <conio.h>

void dispData(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insertionSort(int a[], int SIZE)
{
    int i, j, temp; // temp = current

    for (i = 1; i < SIZE; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = temp;
        printf("\n\nPass: %d => ", i);
        dispData(a, SIZE); // for print each pass
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

    insertionSort(a, SIZE);

    getch();
    return 0;
}