#include <stdio.h>
#include <stdlib.h>


// defining structure of node(in SLL)
struct node{
    int data;
    struct node *next;

};


// function for sorting SLL ( INSERTION SORT )
struct node *sort_list(struct node *head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    
    if(head == NULL) {
        return head;
    }
    else {
        while(ptr1->next != NULL)
        {
            ptr2 = ptr1 -> next;
            while(ptr2 != NULL)
            {
                if(ptr1->data > ptr2->data)
                {
                    temp = ptr1 -> data;
                    ptr1 -> data = ptr2 -> data;
                    ptr2 -> data = temp;
                }
                ptr2 = ptr2 -> next;
            }
            ptr1 = ptr1 -> next;
        }
        return head; // Had to be added
    }
    
}
