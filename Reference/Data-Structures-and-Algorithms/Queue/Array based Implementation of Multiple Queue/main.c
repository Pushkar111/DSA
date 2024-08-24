// program to implement multiple Queue (using Array).

#include <stdio.h>

#define MAX 30

int QUEUE[MAX];
int rearA = -1, frontA = -1, rearB = MAX, frontB = MAX;



// function for push operation in stack
void EnQueue()
{
    int num, choice;

    if(rearA == rearB-1) {
        printf("\n OVERFLOW!");
    }
    else {
        printf("\n Enter the element to EnQueue in QUEUE : ");
        scanf("%d", &num);
        printf("\n Press 1 to push in QUEUE-A or press 2 to push in QUEUE-B : ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (rearA == -1 && frontA == -1) {
                rearA = frontA = 0;
                QUEUE[rearA] = num;
            } else {
                rearA = rearA + 1;
                QUEUE[rearA] = num;
            }
        }
        else if(choice == 2){
            if (rearB == MAX && frontB == MAX) {
                rearB = frontB = MAX-1;
                QUEUE[rearB] = num;
            }
            else {
                rearB = rearB -1;
                QUEUE[rearB] = num;
            }
            printf("\n %d is enqueued in the QUEUE.", num);
        }
        else
            printf("\n INVALID CHOICE!!");

    }
}


// function for pop operation in stack
int DeQueue()
{
    int value, choice;
    printf("\n Press 1 to pop from QUEUE-A or Press 2 to pop from QUEUE-B : ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (frontA == -1) {
            printf("\n UNDERFLOW!");
        }
        else {
            value = QUEUE[frontA];
            frontA = frontA + 1;
            if (frontA>rearA)
                frontA = rearA = -1;
            printf("\n %d  is successfully popped from QUEUE-A.", value);
        }
    }
    else if(choice == 2){
        if (frontB == MAX) {
            printf("\n UNDERFLOW!");
        }
        else {
            value = QUEUE[frontB];
            frontB = frontB - 1;
            if (frontB<rearB)
                frontB = rearB = MAX;
            printf("\n %d  is successfully popped from QUEUE-B.", value);
        }
    }
    else
        printf("\n INVALID CHOICE!!");
}


// function for peek operation in Stack
void peek()
{
    int val, choice;
    printf("\n Press 1 for peek in QUEUE-A or Press 2 for peek in QUEUE-B : ");
    scanf("%d", &choice);
    if(choice == 1) {
        if (frontA == -1) {
            printf("\n QUEUE-A is Empty.");
        }
        else {
            printf("\n Element at top of QUEUE-A is : %d", QUEUE[frontA]);
        }
    }
    else if (choice == 2) {
        if (frontB == MAX) {
            printf("\n QUEUE-B is Empty.");
        }
        else {
            printf("\n Element at top of QUEUE-B is : %d", QUEUE[frontB]);
        }
    }
    else
        printf("\n INVALID CHOICE!!");
}


// function to print elements of Stack
void display()
{
    int i;
    if (frontA == -1) {
        printf("\n  QUEUE-A is empty.");
    }
    else
    {
        printf("\n Elements of QUEUE-A are : \n");
        for (i = frontA; i <= rearA; i++) {
            printf("  %d\n",QUEUE[i]);
        }
    }
    if (frontB == MAX) {
        printf("\n  QUEUE-B is empty.");
    }
    else {
        printf("\n Elements of QUEUE-B are : \n");
        for (i = frontB; i >= rearB; i--) {
            printf("  %d\n",QUEUE[i]);
        }
    }
}



// main function
int main()
{
    int option, val;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n Enter your Choice : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                EnQueue();
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }while(option != 5);

    return 0;

}