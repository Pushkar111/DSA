#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ROW, COL;

    printf("Enter number of rows : ");
    scanf("%d", &ROW);
    printf("Enter number of columns : ");
    scanf("%d", &COL);

    // Allocate memory for 2D array
    int **arr = (int **)calloc(ROW, sizeof(int *));
    for (int i = 0; i < ROW; i++)
    {
        arr[i] = (int *)calloc(COL, sizeof(int));
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("Enter value of arr[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    for (int i = 0; i < ROW; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}