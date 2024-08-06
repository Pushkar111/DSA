#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1; // Empty stack

// Time Complexity -> o(1)
void push(int no)
{
    if (top == SIZE - 1)
    {
        printf("\nStack OverFlow(Full Stack)");
    }
    else
    {
        top++;
        stack[top] = no; // not require to write 17 number line if → stack[++top] = no;
    }
}

// Time Complexity -> o(1)
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        printf("\npop Element : %d", stack[top]);
        top--;
    }
}

void display()
{
    int i, count = 0;
    if (top == -1)
    {
        printf("\nStack underflow(Empty Stack)");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
            count++;
        }
    }
    printf("\nNo of Elements in Stack : %d", count);
}

void peep(int location)
{
    int index;

    if (top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        index = top - location + 1;

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

void change(int location, int no)
{
    int index;

    if (top == -1)
    {
        printf("\nStack Underflow(Empty Stack)");
    }
    else
    {
        index = top - location + 1;

        if (index >= 0 && index <= SIZE)
        {
            stack[index] = no;
            printf("\nIn Location %d => New Element : %d", location, stack[index]);
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
    while (1)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n                          Stack Operation                       ");
        printf("\n----------------------------------------------------------------");
        printf("\n1. For Push");
        printf("\n2. For Pop");
        printf("\n3. For Display");
        printf("\n4. For peek");
        printf("\n5. For change");
        printf("\n6. For Exit");
        printf("\n----------------------------------------------------------------");

        printf("\nEnter the Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the No : ");
            scanf("%d", &no);
            push(no);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nEnter the Location : ");
            scanf("%d", &location);
            peep(location);
            break;

        case 5:
            printf("\nEnter the Location : ");
            scanf("%d", &location);
            printf("\nEnter the No u want to change : ");
            scanf("%d", &no);
            change(location, no);
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
    -> Stack is an ordered collection of ab elements in which
       insertion and deletions are restricted to one end.The end
       from which elements are occupied or removed is referred as top of stack.
----------------------------------------------------------------
List out Basic Operations on Stack :
    1) push operation
    2) pop operation
    3) display operation
    4) peek operation
    5) isEmpty: Returns true if stack is empty, else false.
    6) isFull : returns true if the stack is full else false
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
                      onto a stack is known as a Push Operation.

-> it is used to add data in stack
-> it is used to insert data in stack
-> if stack is full then stack is overflown

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