#include<stdio.h>
#include<stdlib.h>

// Link list node
struct node
{
    int data;
    struct node* next;
};


// Function to get the middle of the linked list

/* if total element is even then it will have 2 middle,
   then it returns 2nd middle element */

void printMiddle(struct Node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("\n The middle element is %d", slow_ptr->data);
    }
}
