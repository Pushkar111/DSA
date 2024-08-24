#include <stdio.h>
#include <stdlib.h>

// defining the structure of a node in DLL
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// function to delete element from the end of SLL
struct node *delete_End(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;

    if (head == NULL)
    {
        printf("SLL is empty!(Underflow!!)");
        return head;
    }
    else if (ptr->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);

        return head;
    }
}
