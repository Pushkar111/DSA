/*
Selection Sort:
    Best Case: 𝑂(𝑛2)
    Average Case: O(n2)
    Worst Case: O(n2)
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

void selectionSort()
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
        dispData(); // print array of each pass
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
    
    selectionSort(); 

    getch();
    return 0;
}