#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5000

char stack[SIZE];

int top = -1; // -1 -> EMPTY

// Time Complexity -> o(1)
void push(char str[])
{
    if (top == SIZE - 1)
    {
        printf("\nStack OverFlow(Full Stack)");
    }
    else
    {
        top++;
        stack[top] = str;
    }
}

// Time Complexity -> o(1)
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        printf("\npop Element : %c", stack[top]);
        top--;
    }
}

void display()
{
    int i, count = 0;
    if (top == -1)
    {
        printf("\nStack underflow(Empty Stack)");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("\n %c", stack[i]);
            count++;
        }
    }
    printf("\nNo of Elements in Stack : %d", count);
}

void peep(int location)
{
    int index;

    if (top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        index = top - location + 1;

        if (index >= 0 && index <= SIZE)
        {
            printf("\nIn Location %d => Element : %c", location, stack[index]);
        }
        else
        {
            printf("\nInvalid Location");
        }
    }
}

int main()
{
    int choice;
    int location;
    int i;
    char str[30];

    printf("\nEnter the String : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    printf("\nstr = %s", str);

    printf("\nREVERSE => \n");
    display();

    return 0;
}