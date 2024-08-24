// program to implement a priority queue.
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};


struct node *start=NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
struct node *deleteSLL(struct node *);


// main function
int main()
{
    int option;

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT ELEMENT");
        printf("\n 2. DELETE ELEMENT");
        printf("\n 3. DISPLAY");
        printf("\n 4. DELETE PRIORITY QUEUE");
        printf("\n 5. EXIT\n");
        printf("\n Enter your option : ");
        scanf( "%d", &option);
        switch(option)
        {
            case 1:
                start = insert(start);
                break;
            case 2:
                start = delete(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                start = deleteSLL(start);
                break;

        }
    }while(option != 5);
}


// function to insert element in priority Queue
// element can be inserted at any priority in Priority Queue!!
struct node *insert(struct node *start)
{
    int val, pri;
    struct node *newNode, *p;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value and its priority : " );
    scanf( "%d %d", &val, &pri);

    newNode->data = val;
    newNode->priority = pri;

    if(start == NULL || pri < start->priority )
    {
        newNode->next = start;
        start = newNode;
    }
    else
    {
        p = start;
        while(p->next != NULL && p->next->priority <= pri)
            p = p->next;

        newNode->next = p->next;
        p->next = newNode;
    }

    return start;

}


// function to delete node in priority Queue-
// first node is always deleted in this!!
struct node *delete(struct node *start)
{
    struct node *ptr;

    if(start == NULL) {
        printf("\n UNDERFLOW" );
    }
    else {
        ptr = start;
        printf("\n Deleted item is: %d [priority= %d]", ptr->data, ptr->priority);
        start = start->next;
        free(ptr);
    }
    return start;

}


// function to print elements of priority Queue
void display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if(start == NULL)
        printf("\nQUEUE IS EMPTY" );
    else
    {
        printf("\n PRIORITY QUEUE IS : " );
        while(ptr != NULL)
        {
            printf( " %d ", ptr->data, ptr->priority );
            if(ptr->next != NULL){
                printf(" -> ");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }

}


// function to delete entire SLL/ Priority Queue
struct node *deleteSLL(struct node *head) {
    struct node *ptr, *temp;
    temp = head;
    if(head == NULL) {
        printf("\n Priority Queue is already Empty!");
    }
    else {
        while (temp != NULL) {
            ptr = temp->next;
            free(temp);
            temp = ptr;
        }
        printf("\n Priority Queue is Deleted!");
        head = temp;
    }
    return head;
}

