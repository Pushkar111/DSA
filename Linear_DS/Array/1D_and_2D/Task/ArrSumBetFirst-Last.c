// Task = Sum of between first and last element entered array

#include <stdio.h>
#include <conio.h>
#define SIZE 5

int main()
{
    int i;
    int no, temp;
    int sum = 0;
    int a[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        printf("\nenter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe Arr is \n");
    printf("--------------------------------------------------------\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
    
    for ( i = 0; i < SIZE; i++)
    {
        no = a[i];
        no /= 10;
        sum = 0;

        while (no > 9)
        {
            temp = no % 10;
            sum = sum + temp;
            no /= 10;
        }
        a[i] = sum;
    }

    printf("\n\nSum of array between 1st and last digit\n");
    printf("---------------------------------------------\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
    
    
    getch();
    return 0;
}