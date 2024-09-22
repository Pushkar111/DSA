#include <stdio.h>
#include <limits.h>

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
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty())
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
    if (isEmpty())
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
void printQueuePriorityWise()
{
    if (isEmpty())
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
    enQueue(10, 1);
    enQueue(20, 3);
    enQueue(30, 2);

    printf("Before dequeue:\n");
    printQueuePriorityWise();

    printf("\nDequeue the element with the highest priority:\n");
    deQueue();

    printf("\nAfter dequeue:\n");
    printQueuePriorityWise();

    return 0;
}
