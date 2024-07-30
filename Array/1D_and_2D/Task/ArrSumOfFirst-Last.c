// Task = Sum of first and last element entered array
#include <stdio.h>
#include <conio.h>
#define SIZE 5

int main()
{
    int i;
    int no;
    int temp;
    int lDigit = 0, fDigit = 0;
    int sum = 0;
    int a[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe Arr is \n");
    printf("--------------------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        no = a[i];
        sum = 0;
        lDigit = no % 10;

        while (no > 9)
        {
            no /= 10;
        }
        fDigit = no;
        sum = fDigit + lDigit;
        a[i] = sum;
    }

    printf("\n\nAfter Sum of first and last element entered array");
    printf("\n--------------------------------------------------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    getch();
    return 0;
}