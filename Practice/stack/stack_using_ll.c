#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int no)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = no;
    ptr->next = top;
    top = ptr;

    return top;
}

struct node *pop(struct node *top)
{
    if (isEmpty(top))
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nPoped Element is : %d", top->data);
        top = top->next;
    }
}

struct node *peek(struct node *top)
{
    if (isEmpty(top))
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nTop Element is : %d", top->data);
    }
}

void *display(struct node *top)
{
    struct node *ptr = top;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice, no;
    struct node *top = NULL;

    while (1)
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the no : ");
            scanf("%d", &no);
            top = push(top, no);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            top = peek(top);
            break;

        case 4:
            display(top);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}