#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 // Maximum size of the priority queue

int dataQueue[SIZE];     // Array to store the data
int priorityQueue[SIZE]; // Array to store the priority of each element

int front = -1, rear = -1; // Pointers for the front and rear of the queue

// Check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Check if the queue is full
int isFull()
{
    return rear == SIZE - 1;
}

// Enqueue operation to insert an element with a priority into the queue
void enQueue(int data, int priority)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1)
    {
        // If queue is empty, set both front and rear to 0
        front = 0;
    }

    // Increment rear and insert the data and its priority
    rear++;
    dataQueue[rear] = data;
    priorityQueue[rear] = priority;
}

// Dequeue operation to remove the element with the highest priority
void deQueue()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    // Find the index of the element with the highest priority
    int maxPriorityIndex = front;
    for (int i = front + 1; i <= rear; i++)
    {
        if (priorityQueue[i] > priorityQueue[maxPriorityIndex])
        {
            maxPriorityIndex = i;
        }
    }

    // Dequeue the element with the highest priority by shifting elements
    printf("Dequeued: %d with priority: %d\n", dataQueue[maxPriorityIndex], priorityQueue[maxPriorityIndex]);

    // Shift elements to the left to remove the dequeued element
    for (int i = maxPriorityIndex; i < rear; i++)
    {
        dataQueue[i] = dataQueue[i + 1];
        priorityQueue[i] = priorityQueue[i + 1];
    }

    rear--; // Decrease the rear pointer

    // If the queue becomes empty after dequeuing, reset front and rear
    if (rear < front)
    {
        front = rear = -1;
    }
}

// Function to print the queue in priority order
void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    // Temporary arrays to sort by priority
    int tempData[SIZE], tempPriority[SIZE];
    for (int i = front; i <= rear; i++)
    {
        tempData[i] = dataQueue[i];
        tempPriority[i] = priorityQueue[i];
    }

    // Sort the elements by priority (simple bubble sort)
    for (int i = front; i <= rear; i++)
    {
        for (int j = i + 1; j <= rear; j++)
        {
            if (tempPriority[i] < tempPriority[j])
            {
                // Swap priorities
                int tempPri = tempPriority[i];
                tempPriority[i] = tempPriority[j];
                tempPriority[j] = tempPri;

                // Swap corresponding data
                int tempDat = tempData[i];
                tempData[i] = tempData[j];
                tempData[j] = tempDat;
            }
        }
    }

    // Display the sorted queue elements
    printf("Queue elements (data, priority) in priority order:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("(%d, %d) ", tempData[i], tempPriority[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data, priority;
    while (1)
    {
        printf("\n==============================================");
        printf("\n            Priority Queue Operation");
        printf("\n==============================================");
        printf("\n1. enQueue");
        printf("\n2. deQueue");
        printf("\n3. display");
        printf("\n4. Exit");
        printf("\n==============================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enQueue(data, priority);
            break;

        case 2:
            printf("Before dequeue:\n");
            display();

            printf("\nDequeue the element with the highest priority:\n");
            deQueue();

            printf("\nAfter dequeue:\n");
            display();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
