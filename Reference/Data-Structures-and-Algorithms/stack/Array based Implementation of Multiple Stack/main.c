// program to implement multiple stacks (using Array).

#include <stdio.h>

#define MAX 20

int stack[MAX];
int topA = -1;
int topB = MAX;


// function for push operation in stack
void push()
{
    int num, choice;
    if(topA == topB-1) {
        printf("\n OVERFLOW!");
    }
    else {
        printf("\n Enter the element to push in Stack : ");
        scanf("%d", &num);
        printf("\n Press 1 to push in Stack-A or press 2 to push in Stack-B : ");
        scanf("%d", &choice);
        if (choice == 1) {
            topA = topA + 1;
            stack[topA] = num;
        }
        else {
            topB = topB - 1;
            stack[topB] = num;
        }
        printf("\n %d is pushed in Stack.", num);
    }
}


// function for pop operation in stack
int pop()
{
    int value, choice;
    printf("\n Press 1 to pop from stack-A or Press 2 to pop from stack-B : ");
    scanf("%d", &choice);
    if (choice == 1) {
        if (topA == -1) {
            printf("\n UNDERFLOW!");
        }
        else {
            value = stack[topA];
            topA = topA - 1;
        }
    }
    else {
        if (topB == MAX) {
            printf("\n UNDERFLOW!");
        }
        else {
            value = stack[topB];
            topB = topB + 1;
            printf("\n %d  is successfully popped from Stack.", value);
        }
    }
}


// function for peek operation in Stack
void peek()
{
    int val, choice;
    printf("\n Press 1 for peek in Stack-A or Press 2 for peek in Stack-B : ");
    scanf("%d", &choice);
    if(choice == 1) {
        if (topA == -1) {
            printf("\n Stack-A is Empty.");
        }
        else {
            printf("\n Element at top of Stack-A is : %d", stack[topA]);
        }
    }
    else {
        if (topB == MAX) {
            printf("\n Stack-B is Empty.");
        }
        else {
            printf("\n Element at top of Stack-B is : %d", stack[topB]);
        }
    }
}


// function to print elements of Stack
void display()
{
    int i;
    if (topA == -1) {
        printf("\n  Stack-A is empty.");
    }
    else
    {
        printf("\n Elements of Stack-A are : \n");
        for (i = 0; i <= topA; i++) {
            printf("  %d\n",stack[i]);
        }
    }
    if (topB == MAX) {
        printf("\n  Stack-B is empty.");
    }
    else {
        printf("\n Elements of Stack-B are : \n");
        for (i = MAX-1; i >= topB; i--) {
            printf("  %d\n",stack[i]);
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
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n Enter your Choice : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
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

