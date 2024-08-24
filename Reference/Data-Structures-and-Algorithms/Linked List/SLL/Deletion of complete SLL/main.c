#include <stdio.h>
#include <stdlib.h>

// defining the structure of a node in a SLL
struct node{
    int data;
    struct node *next;
};


// function to delete entire SLL
struct node *deleteSLL(struct node *head) {
    struct node *ptr, *temp;
    temp = head;

    while(temp != NULL){
        ptr=temp->next;
        free(temp);
        temp=ptr;
    }
    head= NULL;
    
    return head;
    
}

