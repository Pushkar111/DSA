// Check palindrome string using stack

#include <stdio.h>
#include <string.h>
#define SIZE 30

char stack[SIZE];

void push(char stack[], int *top, char ch)
{
    if (*top == SIZE - 1)
    {
        printf("\nStack Overflow [Full Stack]");
    }
    else
    {
        (*top)++;
        stack[*top] = ch; // not require to write 17 number line if → stack[++(*top)] = ch;
    }
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack Underflow [Empty Stack]");
        return '\0'; 
    }
    return stack[(*top)--];
}

int main()
{
    char str[30], ch;
    int i, top, flag = 1;
    top = -1;

    printf("Enter String : ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        push(stack, &top, ch);
    }

    for (i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        if (top != -1 && ch != pop(stack, &top))
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("\n%s is Palindrome String", str);
    }
    else
    {
        printf("\n%s is not Palindrome String", str);
    }

    return 0;
}