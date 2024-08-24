// program to implement a linked stack.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// defining the structure of a node (in Stack )
struct node
{
    int data;
    struct node *next;
};


struct node *top = NULL;
struct node *insert_end(struct node *, int);
void display(struct node *);
struct node *pop(struct node *);
int peek(struct node *);



// peek function
int peek(struct node *top)
{
    if(top == NULL)
        return -1;
    else {
        while(top->next != NULL) {
            top = top->next;
        }
        return top->data;
    }

}



// function to insert element(node) at the end of linked list
// function for push operation
struct node *insert_end(struct node *head, int ele) {
    struct node *new_node, *ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    ptr=head;

    new_node->data= ele;
    new_node->next= NULL;

    if(ptr == NULL){
        ptr=new_node;
        head=ptr;
    }
    else {

        // Traverse to the last node
        while (ptr != NULL && ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node; // Link address part
    }

    return head;

}



// function to print the elements of the stack(Linked List Implementation)
void display(struct node *top)
{
    struct node *ptr;
    ptr = top;
    if(top == NULL)
        printf("\n STACK IS EMPTY (UNDERFLOW)");
    else {
        while(ptr != NULL)
        {
            printf("\n %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
    free(ptr);

}



// function to delete element from the end of SLL
// function for pop operation
struct node *delete_End(struct node *head){
    struct node *ptr, *temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    temp=head;

    if(head == NULL) {
        printf("SLL is empty! ( UNDERFLOW )");
        exit(0);
    }
    else {
        while(ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);

        return head;
    }

}



// main function
int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                top = insert_end(top, val); // function for push operation
                break;
            case 2:
                top = delete_End(top); // function for pop operation
                printf("\nThe Stack after pop operation :");
                display(top);
                break;
            case 3:
                val = peek(top);
                if (val != -1)
                    printf("\n The value at the top of stack is: %d\n", val);
                else
                    printf("\n STACK IS EMPTY (UNDERFLOW)\n");
                break;
            case 4:
                printf("\nThe Stack is :");
                display(top);
                printf("\n");
                break;
        }
    }while(option != 5);

    return 0;

}










