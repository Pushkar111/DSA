#include <stdio.h>
#include <string.h>

void reverseString(char name[], char rev[])
{
    // Base case: if the string is empty, return early
    if (name[0] == '\0')
    {
        return;
    }
    else
    {
        // Recursive case: call reverseString on the rest of the string
        reverseString(name + 1, rev);
        
        // Append the first character of the string to the end of the reversed string
        // This is done by finding the index of the last character in the original string
        // and assigning the first character of the original string to that index
        rev[strlen(name) - 1] = name[0];
    }
}

int main()
{
    char name[100];
    char rev[100] = "";

    printf("Enter a string: ");
    scanf("%s", name);

    reverseString(name, rev);

    printf("Original String is : %s\n", name);
    printf("Reverse String is : %s", rev);
    return 0;
}