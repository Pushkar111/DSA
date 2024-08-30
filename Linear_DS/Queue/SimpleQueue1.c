#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1;

void enQueue(int queue[], int no)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is Overflow(full)");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        else
        {
            rear++;
            queue[rear] = no;
        }
    }
}

void deQueue(int queue[])
{
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else
    {
        // last element of queue
        if (front == rear)
        {
            printf("\n%d is deleted", queue[front]);
            front = -1;
            rear = -1;
        }
        else
        {
            printf("\n%d is deleted", queue[front]);
            front++;
        }
    }
}

void countEmptySpace(int queue[])
{
    int count = 0;
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
        count = SIZE; // All spaces are empty
    }
    else if (rear == front)
    {
        printf("\nQueue is Overflow(full)");
        count = 0;
    }
    else
    {
        // 1  2  3  4  5
        // front = 0, rear = 4
        // count = 4 - 0 + 1 = 5

        // 2  3  4  5
        // front = 1, rear = 4
        // count = 4 - 1 + 1 = 4

        // 3  4  5
        // front = 2, rear = 4
        // count = 4 - 2 + 1 = 3
        if (front <= rear)
        {
            count = rear - front + 1;
        }
        else
        {
            count = SIZE - front + rear + 1;
        }
    }
    printf("\nCount of Empty Space in Queue : %d", SIZE - count);
}

void display(int queue[])
{
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else
    {
        printf("Queue : \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d => %d\n", i, queue[i]);
        }
    }
}

void findMaxMin(int queue[])
{
    int i;
    int max, min;

    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else
    {
        min = queue[front];
        max = queue[front];

        for (i = front; i <= rear; i++)
        {
            if (queue[i] > max)
            {
                max = queue[i];
            }
            if (queue[i] < min)
            {
                min = queue[i];
            }
        }
    }
    printf("\nMaximum element in the queue : %d", max);
    printf("\nMinimum element in the queue : %d", min);
}

void sort(int queue[])
{
    int temp, i, j;

    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            for (j = i + 1; j <= rear; j++)
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    printf("\nQueue is sorted in ascending order.");
}

int main()
{
    int queue[SIZE];

    int choice, no;
    while (1)
    {
        printf("\n==============================================");
        printf("\n            Queue Operation");
        printf("\n==============================================");
        printf("\n1. enQueue");
        printf("\n2. deQueue");
        printf("\n3. display");
        printf("\n4. Count Empty Spaces");
        printf("\n5. Find Max and Min");
        printf("\n6. Sort");
        printf("\n7. Exit");
        printf("\n==============================================");

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
            countEmptySpace(queue);
            break;

        case 5:
            findMaxMin(queue);
            break;

        case 6:
            sort(queue);
            break;

        case 7:
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}

/*
Q. What is Queue in Data Structures?
-> A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle.
   It operates like a line where elements are added at one end (rear) and removed from the other end (front).

➤ Basic Operations of Queue Data Structure
--------------------------------------------
1. Enqueue (Insert): Adds an element to the rear of the queue.
2. Dequeue (Delete): Removes and returns the element from the front of the queue.
3. Peek: Returns the element at the front of the queue without removing it.

➤ Applications of Queue
------------------------
-> Task scheduling in operating systems
-> Data transfer in network communication
-> Simulation of real-world systems (e.g., waiting lines)
-> Priority queues for event processing queues for event processing

➤ Implementation of Queues
----------------------------
-> Queues can be implemented using Two techniques:
    1. Implementations of Queue Data Structure using Arrays
    2. Implementations of Queue Data Structure using Linked List

➤ Types of Queues:
-------------------
    1) Simple Queue: Simple queue also known as a linear queue is the most basic version of a queue.
                     Here, insertion of an element i.e. the Enqueue operation takes place at the rear end and removal of an element
                     i.e. the Dequeue operation takes place at the front end.

    2) Circular Queue:  This is mainly an efficient array implementation of Simple Queue.
                        In a circular queue, the element of the queue act as a circular ring.
                        The working of a circular queue is similar to the linear queue except for the fact that the last element is connected to the first element.
                        Its advantage is that the memory is utilized in a better way. This is because if there is an empty space
                        i.e. if no element is present at a certain position in the queue, then an element can be easily added at that position.

    3) Priority Queue: This queue is a special type of queue.
                       Its specialty is that it arranges the elements in a queue based on some priority.
                       The priority can be something where the element with the highest value has the priority so it creates a queue with decreasing order of values.
                       The priority can also be such that the element with the lowest value gets the highest priority so in turn it creates a queue with increasing order of values.

    4) Dequeue: Dequeue is also known as Double Ended Queue. As the name suggests double ended,
                it means that an element can be inserted or removed from both the ends of the queue unlike the other queues
                in which it can be done only from one end. Because of this property it may not obey the First In First Out property.
*/