#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int SIZE, i;

    printf("Enter the size of array: ");
    scanf("%d", &SIZE);

    ptr = (int *)calloc(SIZE, sizeof(int)); // same size - multiple block 

    // If calloc() is unable to allocate the required memory, it returns a null pointer. 
    // This is a common idiom in C to check for failure to allocate memory. 
    // If the call to calloc() returns a null pointer, it means that the memory allocation request was not successful, 
    // and the program should handle this situation appropriately, typically by terminating the program or performing some form of error handling.
    if (ptr == NULL)
    {
        printf("\nMemory not allocated");
        exit(0);
    }
    else
    {
        printf("\nMemory successfully allocated using calloc()\n");
        for (i = 0; i < SIZE; i++)
        {
            printf("Enter the value of ptr[%d]: ", i);
            scanf("%d", &ptr[i]);
        }

        printf("\nElements of array: ");
        for (i = 0; i < SIZE; i++)
        {
            printf("%d\t", ptr[i]);
        }
        free(ptr);
    }

    return 0;
}