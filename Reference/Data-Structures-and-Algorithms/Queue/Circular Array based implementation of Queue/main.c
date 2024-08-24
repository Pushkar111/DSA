// program to implement a circular queue.
#include <stdio.h>
#include <conio.h>

#define MAX 10  // defining the maximum size of Queue

int queue[MAX];
int front = -1, rear = -1;
void EnQueue(void);
int DeQueue(void);
int peek(void);
void display(void);

// main function
int main()
{
    int option, val;

    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                EnQueue();
                break;
            case 2:
                val = DeQueue();
                if(val != -1)
                    printf("\n The number deleted is : %d", val);
                break;
            case 3:
                val = peek();
                if(val != -1)
                    printf("\n The first value in queue is : %d", val);
                break;
            case 4:
                display();
                break;
        }
    }while(option != 5);

    return 0;

}


// EnQueue operation for Circular Queue
void EnQueue()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);

    if(front == 0 && rear == MAX-1) // when Circular Queue is Full
        printf("\n OVERFLOW");

    else if(front == -1 && rear == -1) // when Circular Queue is Empty
    {
        front = rear = 0;
        queue[rear] = num;
    }

    else if(rear == MAX-1 && front != 0)
    {
        rear=0;
        queue[rear] = num;
    }

    else
    {
        rear = rear+1;
        queue[rear] = num;
    }

}


// DeQueue operation for Circular Queue
int DeQueue() {

    int val;
    if(front == -1 && rear == -1)  // when Circular Queue is Empty
    {
        printf("\n UNDERFLOW");
        return -1;
    }

    else if(front == rear)  // when Circular Queue has only 1 element
    {
        val = queue[front];
        front = rear = -1;
    }

    else {
        val = queue[front];

        if(front == MAX-1)
            front = 0;
        else
            front = front + 1;

    }
    return val;

}


// peek function for Circular Queue
int peek()
{
    if(front == -1 && rear == -1) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }

    else {
        return queue[front];
    }

}


// function to display elements of the Circular Queue
void display()
{
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
        printf ("\n QUEUE IS EMPTY");

    else {

        if(front<rear) {
            for(i=front; i<=rear; i++)
                printf("\t %d", queue[i]);
        }

        else {
            for(i=front; i<MAX; i++)
                printf("\t %d", queue[i]);

            for(i=0; i<=rear; i++)
                printf("\t %d", queue[i]);

        }

    }
}

