#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int SIZE, i, choice;
    int min, max, sum = 0, avg;

    printf("Enter the size of array : ");
    scanf("%d", &SIZE);

    ptr = (int *)calloc(SIZE, sizeof(int));

    if (ptr == NULL)
    {
        printf("\nMemory not allocated");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using calloc()\n");
        for (i = 0; i < SIZE; i++)
        {
            printf("Enter the value of ptr[%d] : ", i);
            scanf("%d", &ptr[i]);
        }
        printf("\nElements of array : ");
        for (i = 0; i < SIZE; i++)
        {
            printf("%d\t", ptr[i]);
        }
        while (1)
        {
            printf("\n------------------------------------------------");
            printf("\nChoose what you want to do : ");
            printf("\n------------------------------------------------");
            printf("\n1. Find out Max From array");
            printf("\n2. Find out Min From array");
            printf("\n3. Find out Sum From array");
            printf("\n4. Find out Average From array");
            printf("\n5. Exit");
            printf("\n------------------------------------------------");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                max = ptr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (ptr[i] > max)
                    {
                        max = ptr[i];
                    }
                }
                printf("\nMaximum Element in array is : %d", max);
                break;

            case 2:
                min = ptr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (ptr[i] < min)
                    {
                        min = ptr[i];
                    }
                }
                printf("\nMinimum Element in array is : %d", min);
                break;

            case 3:
                sum = 0;
                for (i = 0; i < SIZE; i++)
                {
                    sum = sum + ptr[i];
                }
                printf("\nSum of all elements in array is : %d", sum);
                break;

            case 4:
                avg = sum / SIZE;
                printf("\nAverage of all elements in array is : %d", avg);
                break;

            case 5:
                free(ptr);
                exit(0);

            default:
                printf("\nWrong Choice");
            }

        } // end of while
        return 0;
    }
}
