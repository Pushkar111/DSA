// function to swap two adjacent nodes in a SLL

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// defining structure of node in SLL
struct node {
    int data;
    struct node *next;
};



// variable 'index' is the index of SLL after which we want to swap two nodes
struct node *swapNodes(struct node *head, int index) {
    struct node *ptr;
    struct node *p, *q; // variable for pointing the nodes, which we want to swap
    ptr=head;
    int i=0;

    // traversing the ptr to that node after which we want to swap two nodes
    while(i<index) {
        ptr=ptr->next;
        i++;
    }

    p=ptr->next;
    q=p->next;

    p->next=q->next;
    q->next=p;
    ptr->next=q;

    return head; // final sll (swapped one) is returned
}
