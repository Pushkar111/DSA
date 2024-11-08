#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void InsertRear(int no) // simple Queue enQueue
{
    if (rear == SIZE - 1) // 1. Overflow
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

void DeleteFront()
{
    if (front == -1) // 1 Underflow
    {
        printf("\nQueue is Underflow");
    }
    else if (front == rear) // 2. check for last
    {
        printf("%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else // 3. other
    {
        printf("%d is deleted", queue[front]);
        front++;
    }
}

void InsertFront(int no)
{
    if (front == 0 && rear == SIZE - 1) // 1. Overflow
    {
        printf("\nQueue is Overflow");
    }
    else if (front == -1 && rear == -1) // 2. check for 1st
    {
        front = 0;
        rear = 0;
        queue[front] = no;
    }
    else if (front > 0) // 3. else if front > 0
    {
        front--;
        queue[front] = no;
    }
}

void DeleteRear()
{
    if (front == -1 && rear == -1) // 1. Underflow
    {
        printf("\nQueue is Underflow");
    }
    else if (front == rear) // 2. check for last
    {
        printf("%d is deleted", queue[front]);
        front = -1;
        rear = -1;
    }
    else // 3. other
    {
        printf("%d is deleted", queue[rear]);
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is Underflow");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice, no;

    while (1)
    {
        printf("\n1. For InsertRear");
        printf("\n2. For DeleteFront");
        printf("\n3. For InsertFront");
        printf("\n4. For DeleteRear");
        printf("\n5. For display");
        printf("\n6. For Exit");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the no : ");
            scanf("%d", &no);
            InsertRear(no);
            break;

        case 2:
            DeleteFront();
            break;

        case 3:
            printf("\nEnter the no : ");
            scanf("%d", &no);
            InsertFront(no);
            break;

        case 4:
            DeleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid Choice");
        }
    }
    return 0;
}