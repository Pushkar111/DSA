#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5

int main()
{
    int i, j, k, choice, temp;
    int a[SIZE], b[SIZE], c[SIZE];
    int Int[SIZE];
    char Char[SIZE];
    int IntKey;
    char CharKey;
    int min = 0, mid, max = SIZE - 1, index = -1;

    while (1)
    {
        printf("\n                                     1D Array");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n1.Sorting");
        printf("\n2.Linear Search");
        printf("\n3.Binary Search");
        printf("\n4.1D Calc");
        printf("\n5.exit");
        printf("\n--------------------------------------------------------------------------------");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n1.Int");
            printf("\n2.Char");
            printf("\n3.exit");

            printf("\nEnter the Choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of Int[%d] : ", i);
                    scanf("%d", &Int[i]);
                }

                printf("\nThe Unsorted Array is\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("%d\t", Int[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    for (j = 0; j < SIZE - 1; j++)
                    {
                        if (Int[j] > Int[j + 1])
                        {
                            temp = Int[j];
                            Int[j] = Int[j + 1];
                            Int[j + 1] = temp;
                        }
                    }
                }

                printf("\nThe Sorted Array is\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("%d\t", Int[i]);
                }
                break;

            case 2:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of Char[%d] : ", i);
                    scanf(" %c", &Char[i]);
                }

                printf("\nThe Unsorted Array is\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf(" %c\t", Char[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    for (j = 0; j < SIZE - 1; j++)
                    {
                        if (Char[j] > Char[j + 1])
                        {
                            temp = Char[j];
                            Char[j] = Char[j + 1];
                            Char[j + 1] = temp;
                        }
                    }
                }

                printf("\nThe Sorted Array is\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf(" %c\t", Char[i]);
                }
                break;

            case 3:
                exit(0);
            } // end of switch case 1 sorting
            break;

        case 2:
            printf("\n1.Int");
            printf("\n2.Char");
            printf("\n3.exit");

            printf("\nEnter the choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of int[%d] : ", i);
                    scanf("%d", &Int[i]);
                }

                printf("\nThe Array You Follows\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("%d\t", Int[i]);
                }

                printf("\nEnter the Int Key : ");
                scanf("%d", &IntKey);

                for (i = 0; i < SIZE; i++)
                {
                    if (IntKey == Int[i])
                    {
                        index = i;
                        break;
                    }
                }

                if (index == -1)
                {
                    printf("\n%d is not Found", IntKey);
                }
                else
                {
                    printf("\n%d is found at %d index and %d place", IntKey, index, index + 1);
                }
                break;

            case 2:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of Char[%d] : ", i);
                    scanf(" %c", &Char[i]);
                }

                printf("\nThe Array You Follows\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf(" %c\t", Char[i]);
                }

                printf("\nEnter the Char Key : ");
                scanf(" %c", &CharKey);

                for (i = 0; i < SIZE; i++)
                {
                    if (CharKey == Char[i])
                    {
                        index = i;
                        break;
                    }
                }

                if (index == -1)
                {
                    printf("\n %c is not Found", CharKey);
                }
                else
                {
                    printf("\n %c is found at %d index and %d place", CharKey, index, index + 1);
                }
                break;

            case 3:
                exit(0);
            } // end of switch case 2 LinSearch
            break;

        case 3:
            printf("\n1.Int");
            printf("\n2.Char");
            printf("\n3.exit\n");

            printf("\nEnter the choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\nPlz Enter the Sorted Array\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of Int[%d] : ", i);
                    scanf("%d", &Int[i]);
                }

                printf("\nThe Array You Follows\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("%d\t", Int[i]);
                }

                printf("\nEnter the Int Key : ");
                scanf("%d", &IntKey);

                while (min <= max)
                {
                    mid = (min + max) / 2;
                    if (Int[mid] == IntKey)
                    {
                        index = mid;
                        break;
                    }
                    else if (IntKey > Int[mid])
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
                    printf("\n%d is not found", IntKey);
                }
                else
                {
                    printf("\n%d is found at %d index and %d place", IntKey, index, index + 1);
                }
                break;

            case 2:
                printf("\nPlz Enter the Sorted Array\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of Char[%d] : ", i);
                    scanf(" %c", &Char[i]);
                }

                printf("\nThe Array You Follows\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf(" %c\t", Char[i]);
                }

                printf("\nEnter the Char Key : ");
                scanf(" %c", &CharKey);

                while (min <= max)
                {
                    mid = (min + max) / 2;
                    if (Char[mid] == CharKey)
                    {
                        index = mid;
                        break;
                    }
                    else if (CharKey > Char[mid])
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
                    printf("\n %c is not found", CharKey);
                }
                else
                {
                    printf("\n %c is found at %d index and %d place", CharKey, index, index + 1);
                }
                break;

            case 3:
                exit(0);
            } // end of switch case 3 BinSearch
            break;

        case 4:
            printf("\n1.Addition");
            printf("\n2.Subtraction");
            printf("\n3.Multiplication");
            printf("\n4.Division");
            printf("\n5.exit");

            printf("\nEnter the Choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of a[%d] : ", i);
                    scanf("%d", &a[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of b[%d] : ", i);
                    scanf("%d", &b[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] + b[i];
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\n%d + %d = %d", a[i], b[i], c[i]);
                }
                break;

            case 2:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of a[%d] : ", i);
                    scanf("%d", &a[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of b[%d] : ", i);
                    scanf("%d", &b[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] - b[i];
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\n%d - %d = %d", a[i], b[i], c[i]);
                }
                break;

            case 3:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of a[%d] : ", i);
                    scanf("%d", &a[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of b[%d] : ", i);
                    scanf("%d", &b[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] * b[i];
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\n%d * %d = %d", a[i], b[i], c[i]);
                }
                break;

            case 4:
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of a[%d] : ", i);
                    scanf("%d", &a[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\nEnter the value of b[%d] : ", i);
                    scanf("%d", &b[i]);
                }

                for (i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] / b[i];
                }

                for (i = 0; i < SIZE; i++)
                {
                    printf("\n%d / %d = %d", a[i], b[i], c[i]);
                }
                break;

            case 5:
                exit(0);
            } // end of switch case 4 1d Calc
            break;

        case 5:
            exit(0);
        } // end of switch
        getch();
    } // end of while
    return 0;
} // end of main