#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5

int main()
{
    int choice;
    int a[SIZE], index = -1;
    int key, i;
    int min = 0, mid, max = SIZE - 1;

    while (1)
    {

        printf("\n----------------------------------------------------------------");
        printf("\n                          Searching                             ");
        printf("\n----------------------------------------------------------------");
        printf("\n1. Linear search");
        printf("\n2. Binary search");
        printf("\n3. Exit");
        printf("\n----------------------------------------------------------------");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (i = 0; i < SIZE; i++)
            {
                printf("Enter the value of a[%d]: ", i);
                scanf("%d", &a[i]);
            }

            printf("\nArray is : \n");
            printf("------------------------------------------\n");
            for (i = 0; i < SIZE; i++)
            {
                printf("%d\t", a[i]);
            }

            printf("\nEnter the key for Search : ");
            scanf("%d", &key);

            for (i = 0; i < SIZE; i++)
            {
                if (a[i] == key)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                printf("\n%d key is not found", key);
            }
            else
            {
                printf("\n%d key is found at index %d", key, index);
            }
            break;

        case 2:
            printf("\nPlz Enter the Sorted Array\n");
            for (i = 0; i < SIZE; i++)
            {
                printf("Enter the value of a[%d] : ", i);
                scanf("%d", &a[i]);
            }

            printf("\nArray is : \n");
            printf("------------------------------------------\n");
            for (i = 0; i < SIZE; i++)
            {
                printf("%d\t", a[i]);
            }

            printf("\nEnter the key for Search : ");
            scanf("%d", &key);

            while (min <= max)
            {
                mid = (min + max) / 2;
                if (a[mid] == key)
                {
                    index = mid;
                    break;
                }
                else if (key > a[mid])
                {
                    min = mid + 1;
                }
                else
                {
                    max = mid - 1;
                }
            }

            if (index == -1)
            {
                printf("\n%d key is not found", key);
            }
            else
            {
                printf("\n%d key is found at index %d", key, index);
            }
            break;

        case 3:
            exit(0);
            break;
        } // end of switch
        getch();
    }

    getch();

    return 0;
}