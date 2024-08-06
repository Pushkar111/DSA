#include <stdio.h>
#define SIZE 10

int main()
{
    int a[SIZE], i, no;
    int odd = 1;
    int j, flag = 1;


    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        no = a[i];
        flag = 1;
        for (j = 2; j < no; j++)
        {
            if (a[i] % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            if (a[i] != 2 && a[i] != 1)
            {
                printf("a[%d] = %d", i, a[i]);
            }
        }
        printf("\n");
    }

    return 0;
}