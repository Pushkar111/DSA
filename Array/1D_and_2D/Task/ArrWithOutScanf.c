/* Print First 10 Prime Array Number without using Scanf Function*/
#include <stdio.h>
#include <conio.h>
#define SIZE 10

int main()
{
    int a[SIZE], flag = 1, i;
    int count = 0;
    int no = 2;

    while (count < SIZE)
    {
        flag = 1;

        for (i = 2; i < no; i++)
        {
            if (no % i == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            a[count] = no;
            count++;
        }
        no++;
    }

    printf("\nFirst %d prime Without Scanf Function",SIZE);
    printf("\n----------------------------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    getch();
    return 0;
} // end of main