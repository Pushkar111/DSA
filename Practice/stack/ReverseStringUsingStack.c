#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

char stack[SIZE];
int top = -1;

void push(char ch)
{
    if (top == SIZE - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%c ", stack[i]);
        }
    }
}

int main()
{
    char str[SIZE];
    printf("Enter String : ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    printf("\nReversed String : ");
    display();

    return 0;
}