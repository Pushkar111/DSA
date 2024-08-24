// program to implement a linear queue.

#include <stdio.h>
#include <conio.h>

#define MAX 10  // Changing this value will change length of array

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
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. ENQUEUE(INSERT)");
        printf("\n 2. DEQUEUE(DELETE)");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                EnQueue();
                display();
                break;
            case 2:
                val = DeQueue();
                if (val != -1)
                    printf("\n The number deleted is : %d\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("\n The first value in queue is : %d\n", val);
                break;
            case 4:
                display();
                break;
        }
    }while(option != 5);
    getch();
    return 0;
}

// function for "enqueue operation"
// The process of inserting an element in the queue is called enqueue.
// It insert the element at rear position in a Queue
void EnQueue()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if(rear == MAX-1)
        printf("\n OVERFLOW");
    else if(front == -1 && rear == -1)
        front = rear = 0;
    else
        rear=rear+1;

    queue[rear] = num;
}


// function for "dequeue operation"
// The process of deleting an element from the queue is called dequeue.
// It delete and return the element from the front position in a Queue
int DeQueue()
{
    int val;
    if(front == -1 || front > rear) {
        printf("\n UNDERFLOW");
        return -1;
    }
    else {
        val = queue[front];
        front=front+1;
        if(front > rear)
            front = rear = -1;
        return val;
    }
}


// function for "peek operation"
// it return the element present at the front position in Queue.
int peek()
{
    if(front==-1 || front>rear) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else {
        return queue[front];
    }
}


// function to print the element of the Queue
void display()
{
    int i;
    printf("\n Elements of Queue are:\n");
    if(front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else {
        for(i = front; i <= rear; i++)
            printf("  %d\n", queue[i]);
    }
}

