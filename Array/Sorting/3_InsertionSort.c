// Use for small amount of Data
/*
insertion sort
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
    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }
}

void dispData()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insertionSort()
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
        dispData(); // for print each pass
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

    insertionSort();

    getch();
    return 0;
}