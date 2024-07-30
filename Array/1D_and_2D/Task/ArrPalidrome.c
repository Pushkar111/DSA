#include <stdio.h>
#include <conio.h>
#define SIZE 10

int main()
{
    int a[SIZE], i, no, dup, temp;
    int j, rev = 0;

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe arr is\n");
    printf("--------------------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nPalindrome Numbers\n");
    printf("--------------------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        dup = a[i];
        no = dup;
        rev = 0;
        while (no > 0)
        {
            temp = no % 10;
            rev = (rev * 10) + temp;
            no /= 10;
        }
        
        if (dup == rev)
        {
            printf("a[%d] = %d", i, a[i]);   
        }
        printf("\n");
    }

    getch();
    return 0;
}