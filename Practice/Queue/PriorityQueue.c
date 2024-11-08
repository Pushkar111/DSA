#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int dataQueue[SIZE], priorityQueue[SIZE];
int front = -1, rear = -1;

void enQueue(int data, int priority)
{
    if (rear == SIZE - 1) // 1. Overflow
    {
        printf("Queue is Overflow\n");
        return;
    }
    if (front == -1) // 2.check for 1st
    {
        front = 0;
    }
    // 3. rear++, Insert data
    rear++;
    dataQueue[rear] = data;
    priorityQueue[rear] = priority;
}

void deQueue()
{
    if (front == -1) // 1. Underflow
    {
        printf("Queue is Underflow\n");
        return;
    }

    int maxPriorityIndex = front;
    for (int i = front + 1; i <= rear; i++)
    {
        if (priorityQueue[i] > priorityQueue[maxPriorityIndex])
        {
            maxPriorityIndex = i;
        }
    }

    printf("DeQueue : %d with priority: %d\n", dataQueue[maxPriorityIndex], priorityQueue[maxPriorityIndex]);

    for (int i = maxPriorityIndex; i < rear; i++)
    {
        dataQueue[i] = dataQueue[i + 1];
        priorityQueue[i] = priorityQueue[i + 1];
    }

    rear--;

    if (rear < front)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Underflow\n");
        return;
    }
    int tempData[SIZE], tempPriority[SIZE];
    for (int i = front; i <= rear; i++)
    {
        tempData[i] = dataQueue[i];
        tempPriority[i] = priorityQueue[i];
    }

    for (int i = front; i <= rear; i++)
    {
        for (int j = i + 1; j <= rear; j++)
        {
            if (tempPriority[i] < tempPriority[j])
            {
                int temp1 = tempPriority[i];
                tempPriority[i] = tempPriority[j];
                tempPriority[j] = temp1;

                int temp2 = tempData[i];
                tempData[i] = tempData[j];
                tempData[j] = temp2;
            }
        }
    }

    for (int i = front; i <= rear; i++)
    {
        printf("(%d, %d)  ", tempData[i], tempPriority[i]);
    }
}

int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("\n1. enQueue");
        printf("\n2. deQueue");
        printf("\n3. display");
        printf("\n4. Exit");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        // (10, 2)  (20, 1)  (30, 3)  (40, 4)  (50, 0)
        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &data);
            printf("Enter the priority : ");
            scanf("%d", &priority);
            enQueue(data, priority);
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
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}