#include <stdio.h>

#define MAX 10 // Altering this value changes size of stack created

int stack[MAX]; // defining array based stack
int top = -1;

void push(int stack[], int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);


// push function- The new element is always inserted at top position.
void push(int stack[], int val) {
    if(top == MAX-1) {
        printf("\n STACK OVERFLOW");
    }
    else {
        top=top+1;
        stack[top] = val;
    }

}



// pop function- In a stack, the element is always deleted from top position.
int pop(int stack[]) {

    int val;
    if(top == -1) {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else {
        val = stack[top];
        top=top-1;
        return val;
    }

}


// peek function- it returns element at top
int peek(int stack[]) {

    if(top == -1) {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else
        return (stack[top]);

}


// function to print the elements of stack
void display(int stack[]) {
    int i;
    if(top == -1)
        printf("\n STACK IS EMPTY");
    else {
        for(i=top; i>=0; i--)
            printf("\n %d",stack[i]);
        printf("\n"); // Added for formatting purposes
    }
}


// main function
int main() {
    int val, option;
    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\n Enter the number to be pushed in stack: ");
                scanf("%d", &val);
                push(stack, val);
                break;
            case 2:
                val = pop(stack);
                if (val != -1)
                    printf("\n The value deleted from stack is : %d", val);
                break;
            case 3:
                val = peek(stack);
                if (val != -1)
                    printf("\n The value stored at the top of stack is : %d", val);
                break;
            case 4:
                printf("\n Elements of Stack is : \n");
                display(stack);
                break;
        }
    } while (option != 5);
    
    free(stack);
    return 0;
}






