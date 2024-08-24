#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1;

void enQueue(int queue[], int no)
{
    if (front == 0 && rear == SIZE - 1)
    {
        printf("\nQueue is Overflow(full)");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = no;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
        queue[rear] = no;
    }
    else
    {
        rear++;
        queue[rear] = no;
    }
}

void deQueue(int queue[])
{
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else if (front == rear)
    {
        printf("\n%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1)
    {
        printf("\n%d is deleted", queue[front]);
        front = 0;
    }
    else
    {
        printf("\n%d is deleted", queue[front]);
        front++;
    }
}

void display(int queue[])
{
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else
    {
        printf("\nQueue : \n");
        if (front <= rear)
        {
            // SimpleQueue
            for (int i = front; i <= rear; i++)
            {
                printf("%d => %d\n", i, queue[i]);
            }
        }
        else
        {
            // CircularQueue
            for (int i = front; i <= SIZE - 1; i++)
            {
                printf("%d => %d\n", i, queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d => %d\n", i, queue[i]);
            }
        }
    }
}

int main()
{
    int queue[SIZE];
    int choice, no;

    while (1)
    {
        printf("\n============================================");
        printf("\n Circular Queue Operation");
        printf("\n============================================");
        printf("\n1. enQueue");
        printf("\n2. deQueue");
        printf("\n3. display");
        printf("\n4. Exit");
        printf("\n============================================");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter No to enQueue : ");
            scanf("%d", &no);
            enQueue(queue, no);
            break;

        case 2:
            deQueue(queue);
            break;

        case 3:
            display(queue);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}