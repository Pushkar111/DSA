#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1, rear = -1;

void insertRear(int queue[], int no)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is Overflow(full)");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = no;
    }
    else
    {
        rear++;
        queue[rear] = no;
    }
}

void deleteFront(int queue[])
{
    if (front == -1)
    {
        printf("\nQueue is Underflow(empty)");
    }
    else if (front == rear) // last element of queue
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

void insertFront(int queue[], int no)
{
    if (front == 0 && rear == SIZE - 1)
    {
        printf("\nQueue is Overflow (full)");
    }
    else if (front == -1 && rear == -1) // Empty queue
    {
        front = 0;
        rear = 0;
        queue[front] = no;
    }
    else if (front > 0) // Insert at the front
    {
        front--;
        queue[front] = no;
    }
    else
    {
        printf("\nCannot insert at the front (no space)");
    }
}

void deleteRear(int queue[])
{
    if (front == -1 && rear == -1) // Empty queue
    {
        printf("\nQueue is Underflow (empty)");
    }
    else if (front == rear) // Last element in the queue
    {
        printf("\n%d is deleted", queue[rear]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n%d is deleted", queue[rear]);
        rear--;
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
        printf("Queue : \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d => %d\n", i, queue[i]);
        }
    }
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
        printf("\n1. insertRear");
        printf("\n2. deleteFront");
        printf("\n3. insertFront");
        printf("\n4. deleteRear");
        printf("\n5. display");
        printf("\n6. Exit");
        printf("\n==============================================");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter No to enQueue : ");
            scanf("%d", &no);
            insertRear(queue, no);
            break;

        case 2:
            deleteFront(queue);
            break;

        case 3:
            printf("Enter No to enQueue : ");
            scanf("%d", &no);
            insertFront(queue, no);
            break;

        case 4:
            deleteRear(queue);
            break;

        case 5:
            display(queue);
            break;

        case 6:
            exit(0);
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