#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enQueue(int no)
{
    if (rear == SIZE - 1) // 1. overflow
    {
        printf("\nQueue is Overflow");
    }
    else if (front == -1 && rear == -1) // 2. check for 1st
    {
        front = 0;
        rear = 0;
        queue[rear] = no;
    }
    else // 3. other
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
    else if (front == rear) // 2. check for last
    {
        printf("\n%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else // other
    {
        printf("\n%d is deleted", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1) // 1. Underflow
    {
        printf("\nQueue is Underflow");
    }
    else // 2. other
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int queue[SIZE];
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