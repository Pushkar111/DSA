#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5

void push(int stack[], int *top, int no)
{
    if (*top == SIZE - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        (*top)++;
        stack[*top] = no;
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nPOP Element : %d", stack[*top]);
        (*top)--;
    }
}

void peep(int stack[], int *top, int location)
{
    if (*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        int index = *top - location + 1;
        if (index >= 0 && index <= SIZE)
        {
            printf("\n IN LOCATION %d => PEEP Element : %d", location, stack[index]);
        }
        else
        {
            printf("\nInvalid Location");
        }
    }
}

void change(int stack[], int *top, int location, int no)
{
    if (*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        int index = *top - location + 1;
        if (index >= 0 && index <= SIZE)
        {
            stack[index] = no;
            printf("\nIN LOCATION %d => CHANGE Element : %d", location, stack[index]);
        }
        else
        {
            printf("\nInvalid Location");
        }
    }
}

void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    int stack[SIZE];
    int *top;
    *top = -1;
    int choice, location, no;

    while (1)
    {
        printf("\n1. For PUSH");
        printf("\n2. For POP");
        printf("\n3. For PEEP");
        printf("\n4. For CHANGE");
        printf("\n5. For DISPLAY");
        printf("\n6. For EXIT");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the no : ");
            scanf("%d", &no);
            push(stack, top, no);
            break;

        case 2:
            pop(stack, top);
            break;

        case 3:
            printf("\nEnter the location : ");
            scanf("%d", &location);
            peep(stack, top, location);
            break;

        case 4:
            printf("\nEnter the location : ");
            scanf("%d", &location);
            printf("\nEnter the no : ");
            scanf("%d", &no);
            change(stack, top, location, no);
            break;

        case 5:
            display(stack, top);
            break;

        case 6:
            exit(0);
        }
    }

    return 0;
}