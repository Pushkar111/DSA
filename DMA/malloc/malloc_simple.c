#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *ptr;

    ptr = malloc(sizeof(int));

    printf("Enter a number: ");
    scanf("%d", ptr);

    printf("Value of a: %d", *ptr);
    free(ptr);
    
    return 0;
}