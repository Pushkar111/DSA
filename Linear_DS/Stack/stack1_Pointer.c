#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];

void push(int stack[], int *top, int no)
{
    if (*top == SIZE - 1)
    {
        printf("\nStack OverFlow(Full Stack)");
    }
    else
    {
        (*top)++;
        stack[*top] = no;
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        printf("\npop Element : %d", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int *top)
{
    int i, count = 0;
    if (*top == -1)
    {
        printf("\nStack underflow(Empty Stack)");
    }
    else
    {
        for (i = *top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
            count++;
        }
    }
    printf("\nNo of Elements in Stack : %d", count);
}

void peep(int location, int *top)
{
    int index;

    if (*top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {

        index = *top - location + 1;

        if (index >= 0 && index <= SIZE)
        {
            printf("\nIn Location %d => Element : %d", location, stack[index]);
        }
        else
        {
            printf("\nInvalid Location");
        }
    }
}

void change(int location, int *top, int no)
{
    int index;

    if (*top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        index = *top - location + 1;

        if (index >= 0 && index <= SIZE)
        {
            stack[index] = no;
            printf("\nIn Location %d => Change Element : %d", location, stack[index]);
        }
        else
        {
            printf("\nInvalid Location");
        }
    }
}

int main()
{
    int choice, no, location;

    int *top;
    *top = -1; // stack empty
    while (1)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n                          Stack Operation                       ");
        printf("\n----------------------------------------------------------------");
        printf("\n1. For Push");
        printf("\n2. For Pop");
        printf("\n3. For Display");
        printf("\n4. For peek");
        printf("\n5. For Change");
        printf("\n6. For Exit");
        printf("\n----------------------------------------------------------------");

        printf("\nEnter the Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the No : ");
            scanf("%d", &no);
            push(stack, top, no);
            break;

        case 2:
            pop(stack, top);
            break;

        case 3:
            display(stack, top);
            break;

        case 4:
            printf("\nEnter the Location : ");
            scanf("%d", &location);
            peep(location, top);
            break;

        case 5:
            printf("\nEnter the Location : ");
            scanf("%d", &location);
            printf("\nEnter element you want to change : ");
            scanf("%d", &no);
            change(location, top, no);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}

/*
----------------------------------------------------------------
Stack → LiFo -> Last In First Out
----------------------------------------------------------------
Define Stack :
    -> Stack is an linear Data Structure in which
       insertion and deletions are Perform at one end only.
    -> Stack is used to store data in a particular order.
    -> Stack is used to implement LIFO (Last In First Out) 
----------------------------------------------------------------
List out Basic Operations on Stack :
    1) push operation
    2) pop operation
    3) display operation
    4) peek operation
    5) change operation
----------------------------------------------------------------
stack Example [Technical life] :-
    1) Recursion
    2) DFS (Depth First Search)
    3) Backtracking
    4) in memory management
----------------------------------------------------------------
stack Example [practical life] :-
    1)whatsapp -> chat -> msg
    2) email
    3) call-history
    4) stack of plate
    5) gallery
    6) ctrl+z -> stack
----------------------------------------------------------------

1) push() operation :- The process of putting a new data element
                      into a stack is known as a Push Operation.

-> it is used to insert data in stack
-> if stack is full then stack is overflow

=> Algorithm of void push(int no)
    step-1 : Check if stack is full or not
    step-2 : if stack is full
                then produce an error stack overflow and exit
    step-3 : if stack is not full
                then increment top of stack by 1
    step-4 : Add data element to the stack location,
             where top is pointing
    step-5 : End


2) pop() operation : Accessing the content while removing it from the stack, is known as a Pop Operation. In
                    an array implementation of pop() operation, the data element is not actually removed,
                    instead the top is decremented to a lower position in the stack to point to the next value.
                    But in linked-list implementation, pop() actually removes data elements and deallocates
                    memory space

-> it is used to remove data from stack
-> if stack is empty means no elements are available  in stack that means stack is underflow

=> Algorithm of void pop()
    step-1 : check stack is empty or not
    step-2 : if stack is empty
                then produce an error stack underflow and exit
    step-3 : if stack is not empty
                then access the data element at which top is pointing
    step-4 : decrement the top of stack by 1
    step-5 : End


3) display() operation -> it is used to print all the elements available in stack by LIFO(Last in First Out) Style


4) peek() operation : If we want to access some information stored
                      at some location in the stack then peep
                      operation is required.
-> The index value is  top - location + 1
-> it returns the element at given position

=> Algorithm of void peep(int location)
    step-1 : input the location of element that you
             want to change
    step-2 : check the stack is empty or not
    step-3 : if stack is empty
                then produce an error stack underflow and exit
    step-4 : if stack is not empty
                then perform operation index = top - location + 1
    step-5 : if index >= 0 and index <= SIZE
                then print peep element
    step-6 : else print invalid location
    step-7 : End

5) change() operation : If we want to Change some information stored
                      at some location in the stack then change
                      operation is required.
-> The index value is  top - location + 1
-> it change the element at given position

=> Algorithm of void peep(int location)
    step-1 : input the location of element that you
             want to change
    step-2 : check the stack is empty or not
    step-3 : if stack is empty
                then produce an error stack underflow and exit
    step-4 : if stack is not empty
                then perform operation index = top - location + 1
    step-5 : if index >= 0 and index <= SIZE
                then change element
    step-6 : else print invalid location
    step-7 : End

6) top pointer/indicator -> it is use to manage stack

7) condition of stack overflow and stack overflow
-> top == size-1 → [ stack is overflow(full) ]
-> top == -1     → [ stack is underflow(empty) ]

*/