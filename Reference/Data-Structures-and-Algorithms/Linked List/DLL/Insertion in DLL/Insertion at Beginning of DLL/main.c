#include <stdio.h>
#include <stdlib.h>


// defining structure of node in a DLL
struct node{
    int data;
    struct node *prev;
    struct node *next;
};


// function for insertion of node at the beginning of a DLL
struct node *insertBeg(struct node *head, int ele){
    struct node *newNode, *ptr, *temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    ptr=(struct node *)malloc(sizeof(struct node));
    newNode=NULL;

    newNode->data = ele;
    newNode->next = head;


    head = newNode;
    return head;

}
