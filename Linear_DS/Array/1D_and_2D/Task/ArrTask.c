/*
    Task = those elements have one or two digit interchange
           those digits to next 3rd occurrence unique prime.
           and those have more than two digit print center digits sum 
           except first and last
*/
#include <stdio.h>
#include <conio.h>
#include <direct.h>

int main()
{
    int a[] = {2, 3, 123, 4567, 7};
    int i, j, flag = 1, l, m, no, dup, temp, sum = 0, k;

    for (i = 0; i < 5; i++)
    {
        no = a[i];

        if (no > 99)
        {
            sum = 0;
            dup = no;
            dup = dup / 10;
            while (dup > 9)
            {
                temp = dup % 10;
                sum = sum + temp;
                dup = dup / 10;
            }
            a[i] = sum;
        }
        else
        {
            no = a[i];
            no++;
            printf("\na[%d] : %d", i, a[i]);
            for (j = 3; j >= 1;)
            {
                flag = 1;

                for (k = 2; k < no; k++)
                {
                    if (no % k == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    printf("--%d", no);
                    if (j == 1)
                    {
                        a[i] = no;
                    }
                    j--;
                }
                no++;
            }
            printf("\n");
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("\n---A[%d] : %d", i, a[i]);
    }

    getch();
    return 0;
}