#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *enQueue(int no)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (isEmpty())
    {
        front = ptr;
        rear = ptr;
        rear->data = no;
        rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->data = no;
        rear->next = NULL;
    }
}

struct node *deQueue()
{
    if (isEmpty())
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        struct node *ptr = front;
        printf("%d is deleted", ptr->data);
        front = front->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr = front;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int no, choice;

    while (1)
    {
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the no : ");
            scanf("%d", &no);
            enQueue(no);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}