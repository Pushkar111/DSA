#include <stdio.h>
#include <stdlib.h>


// defining structure of node in a DLL
struct node{
    int data;
    struct node *prev;
    struct node *next;
};


// function to insert node at any index in DLL (position =index+1)
// index= position -1
struct node *insert_at_Index(struct node *head, int index, int element, int size){
    struct node *newNode, *ptr;
    int count=0;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr=head;

    if(newNode==NULL){
        printf("Unable to allocate memory.");
        exit(0);
    }
    else if(index <= 0){
        return insertBeg(head, ele);
    }
    else{
        if(index >= size) {
            return insertEnd(head, element);
        }
        else {
            newNode->data = element; // Link data part

            // Traverse to the n-1 position
            while (ptr->next != NULL) {
                ptr = ptr->next;
                count++;
                if (count == index - 1) {
                    break;
                }

            }
            newNode->next = ptr->next;
            newNode->prev = ptr;

            return head;
        }

        }

    }

}


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



