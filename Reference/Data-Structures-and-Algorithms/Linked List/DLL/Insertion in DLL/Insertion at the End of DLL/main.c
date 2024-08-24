#include <stdio.h>
#include <stdlib.h>

// defining structure of node in a DLL
struct node{
    int data;
    struct node *prev;
    struct node *next;
};


// function to insert element at the end of DLL
struct node *insertEnd(struct node *head, int ele){
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr = head;

    newNode->data = ele;
    newNode->next = NULL;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev= ptr;

    free(ptr);

    return head;

}