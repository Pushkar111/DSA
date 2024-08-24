// program to implement a linked Stack.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct stack
{
    int data;
    struct stack *next;
};


struct stack *top = NULL;
struct stack *push(struct stack *, int);
void display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);
struct stack *deleteStack(struct stack *);


int main() {
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. DELETE STACK");
        printf("\n 6. EXIT\n");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if (val != -1)
                    printf("\n The value at the top of stack is: %d", val);
                else
                    printf("\n STACK IS EMPTY");
                break;
            case 4:
                printf("\n Elements of Stack is : \n");
                display(top);
                break;
            case 5:
                top = deleteStack(top);
                printf("\n Stack Deleted!");

        }
    }while(option != 6);

    return 0;
}


// function for push operation
struct stack *push(struct stack *top, int val) {
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr -> data = val;
    if(top == NULL) {
        ptr -> next = NULL;
        top = ptr;
    }
    else {
        ptr -> next = top;
        top = ptr;
    }
    return top;
}


// function for printing elements of Stack
void display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
        printf("\n The Stack is Empty!");
    else {
        while(ptr != NULL) {
            printf("\n %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
}



// function for pop operation
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
        printf("\n UNDERFLOW (Stack is Empty)");
    else {
        top = top -> next;
        printf("\n The value being deleted is: %d", ptr -> data);
        free(ptr);
    }
    return top;
}


// function for peek operation
int peek(struct stack *top) {
    if(top==NULL)
        return -1;
    else
        return top ->data;
}



// function to delete entire Stack
struct stack *deleteStack(struct stack *top) {
    struct stack *ptr, *temp;
    temp = top;

    while(temp != NULL){
        ptr=temp->next;
        free(temp);
        temp=ptr;
    }
    top = temp;
    return top;
}