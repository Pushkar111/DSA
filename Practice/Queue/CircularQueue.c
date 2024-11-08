#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enQueue(int no)
{
    if ((front == 0 && rear == SIZE - 1) || rear == front - 1) // 1. Overflow
    {
        printf("\nQueue is Overflow");
    }
    else if (front == -1 && rear == -1) // 2. check for 1st
    {
        front = 0;
        rear = 0;
        queue[rear] = no;
    }
    else if (rear == SIZE - 1) // 3. when rear is last element
    {
        rear = 0;
        queue[rear] = no;
    }
    else // 4. other
    {
        rear++;
        queue[rear] = no;
    }
}

void deQueue()
{
    if (front == -1) // 1. Underflow
    {
        printf("\nQueue is Underflow");
    }
    else if (front == rear) // 2. when front and rear are same
    {
        printf("\n%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1) // 3. when front is last element
    {
        printf("\n%d is deleted", queue[front]);
        front = 0;
    }
    else // 4. other
    {
        printf("\n%d is deleted", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1) // 1. underflow
    {
        printf("\nQueue is Underflow");
    }
    else // 2. other
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < SIZE; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
    }
}

int main()
{
    int choice, no;

    while (1)
    {
        printf("\n1. For enQueue");
        printf("\n2. For deQueue");
        printf("\n3. For display");
        printf("\n4. For Exit");

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
            printf("\nInvalid Choice");
        }
    }
    return 0;
}