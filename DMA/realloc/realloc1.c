// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     char *str;
//     int SIZE, RESIZE;

//     printf("Enter the size of the string : ");
//     scanf("%d", &SIZE);

//     str = (char *)malloc(SIZE * sizeof(char));

//     printf("Enter a string : \n");
//     strcpy(str, "This is a testing prompt");

//     printf("str = %s, Address = %u\n", str, str);
//     free(str);

//     /* Reallocating memory */
//     printf("Enter the new size of the string : ");
//     scanf("%d", &RESIZE);
//     str = (char *)realloc(str, RESIZE * sizeof(char));
//     strcpy(str, "This is a testing prompt for realloc");
//     printf("str = %s, Address = %u\n", str, str);

//     free(str);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size, resize;
    char *str = NULL;
    printf("Enter limit of the text: \n");
    scanf("%d", &size);
    str = (char *)malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory is successfully allocated using malloc() \n");
        printf("Enter some text : ");
        fflush(stdin);
        gets(str);
        printf("Inputted text by allocating memory using malloc() is: %s\n", str);
    }
    free(str);

    str = (char *)calloc(50, sizeof(char));
    if (str == NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory is successfully allocated using calloc() \n");
        printf("Enter some text : ");
        fflush(stdin); // clearing the buffer
        gets(str);
        printf("Inputted text by allocating memory using calloc() is: %s\n", str);
    }

    printf("Enter the new size: \n");
    scanf("%d", &resize);
    str = (char *)realloc(str, resize * sizeof(char));
    if (str == NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory is successfully reallocated by using realloc() \n");
        printf("Enter some text : ");
        fflush(stdin);
        gets(str);
        printf("Inputted text by reallocating  memory using realloc()is: %s\n", str);
    }
    free(str);

    return 0;
}