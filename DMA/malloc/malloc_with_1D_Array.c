#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int i, SIZE;

    printf("Enter the size of array: ");
    scanf("%d", &SIZE);

    ptr = (int *)malloc(SIZE * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using malloc()\n");
        for (i = 0; i < SIZE; i++)
        {
            printf("Enter the value of ptr[%d]: ", i);
            scanf("%d", &ptr[i]);
        }

        printf("\nElements of array : ");
        for (i = 0; i < SIZE; i++)
        {
            printf("%d\t", ptr[i]);
        }
        free(ptr);
    }

    return 0;
}
