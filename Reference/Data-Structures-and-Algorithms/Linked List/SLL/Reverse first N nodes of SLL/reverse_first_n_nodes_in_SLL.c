/* 14. Write a program to reverse only the first N elements
   of a Singly linked list. */


/* Reverse the first N nodes in the list,
   means the n th node should be the first node and
   first node should be the nth node
   Dont change the data in the nodes, only move the nodes to respective positions
*/

#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
}*head = NULL;


void display(struct node *);
struct node *insert_End(struct node *, int ele);
void Reverse(struct node **, int);


int main()
{
    int n; // n = number of nodes
    int ele; // ele = element which is to be insert in SLL
    int m; // m = number of nodes that has to be Reversed
    int i, j, x;
    printf("\n Enter the number of nodes in SLL : ");
    scanf("%d", &n);

    //Use insert_End and create a SLL with n nodes
    printf("\n Enter the elements to insert at the end of SLL : \n");
    for(i=0; i<n; i++)
    {
       scanf("%d", &ele);
       head = insert_End( head, ele);
    }
    printf("\n\n Entered SLL is : ");
    display(head);

    // Read number of nodes to be reversed
    printf("\n Enter the number of nodes to be Reversed : ");
    scanf("%d", &m);

    if(m <= n && n > 0)
    {
           Reverse(&head, m);
           printf("\n SLL after reverse of %d nodes : ", m);
           display(head);
    }
    else
        printf("\n Reversing is not possible!!");

    return 0;
}



//function to insert element at the end of linked list
struct node *insert_End(struct node *head, int ele)
{
    struct node *newNode, *ptr;
    newNode=(struct node *)malloc(sizeof(struct node));
    ptr=head;

    newNode->data= ele;
    newNode->next= NULL;

    if(ptr == NULL) {
        ptr=newNode;
        head=ptr;
    }
    else if(ptr->next == NULL) {
        ptr->next=newNode;
    }
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}



//function to print element of linked list
void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
        printf("\n SLL is empty!");
    else {
        while (ptr != NULL) {
            printf("  %d ", ptr->data);
            if (ptr->next != NULL) {
                printf("->");
            }
            ptr = ptr->next;
        }
    }
}




// Reverse the first m nodes
void Reverse(struct node **head_ref, int m)
{
    // traverse the linked list until break
    // point not meet
    struct node* temp = *head_ref;
    int count = 1;
    while (count < m) {
        temp = temp->next;
        count++;
    }

    // backup the joint point
    struct node* joint_point = temp->next;
    temp->next = NULL; // break the list

    // reverse the list till break point
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // join both parts of the linked list
    // traverse the list until NULL is not
    // found
    *head_ref = prev;
    current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }

    // joint both part of the list
    current->next = joint_point;

}



