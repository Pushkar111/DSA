#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ROW 3
#define COL 3

int main()
{
    int a[ROW][COL];
    int b[ROW][COL];
    int c[ROW][COL] = {0};
    int i, j, k, choice;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("\nEnter the value of a[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("\nEnter the value of b[%d][%d] : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nThis is the Matrix A\n");
    printf("-----------------------\n");
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nThis is the Matrix B\n");
    printf("-----------------------\n");
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4.Division");
        printf("\n5. Exit");

        printf("\nEnter the Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("\nThis is the Matrix C\n");
            printf("-----------------------\n");
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    printf("%d\t", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("\nThis is the Matrix C\n");
            printf("-----------------------\n");
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    printf("%d\t", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    for ( k = 0; k < COL; k++)
                    {
                        c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
                    }
                }
            }
            printf("\nThis is the Matrix C\n");
            printf("-----------------------\n");
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    printf("%d\t", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 4:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    c[i][j] = a[i][j] / b[i][j];
                }
            }
            printf("\nThis is the Matrix C\n");
            printf("-----------------------\n");
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    printf("%d\t", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 5:
            exit(0);

        default:
            break;
        }
        getch();
    }
    return 0;
}