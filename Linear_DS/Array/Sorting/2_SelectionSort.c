/*
Selection Sort:
    Best Case: 𝑂(𝑛2)
    Average Case: O(n2)
    Worst Case: O(n2)
*/
#include <stdio.h>
#include <conio.h>

// 55 87 65 43 45 67 89

void dispData(int a[], int SIZE)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

void selectionSort(int a[], int SIZE)
{
    int i, j, min, temp;

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
        printf("\n\nPass: %d => ", i + 1);
        dispData(a, SIZE); // print array of each pass
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

    selectionSort(a, SIZE);

    getch();
    return 0;
}