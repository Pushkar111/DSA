#include <stdio.h>
#include <stdio.h>

// defining the structure of node in SLL
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// function to delete first node of SLL
struct node *deleteAtHead(struct node *head)
{
    struct node *ptr;
    ptr = head; // so that we can free the initial space occupied by head later

    if (head == NULL)
    {
        printf("SLLis empty!");
        return head;
    }
    else
    {
        head = head->next;
        free(ptr);
        return head;
    }
}

// function to delete Node from the end of SLL
struct node *deleteAtTail(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = head;

    if (head == NULL)
    {
        printf("SLL is empty!(UNDERFLOW)");
    }
    else if (head->next == NULL)
    {
        head = NULL;
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
    }
    return head;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
struct node *deleteNode(struct node *head, int val)
{
}

// function to delete node from any index in SLL
struct node *deleteAtIndex(struct node *head, int pos, int count)
{
    struct node *ptr, *temp;
    int ind = 0;
    ptr = (struct node *)malloc(sizeof(struct node));
    temp = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    temp = head;

    if (head == NULL)
    {
        printf("List is empty!(UNDERFLOW)");
        return head;
    }
    else
    {
        if (pos == 0 || pos < 0)
        {
            return deleteAtHead(head);
        }
        else if (pos == count - 1 || pos >= count)
        {
            return deleteAtTail(head);
        }
        else
        {
            while (ptr != NULL || ind < pos)
            {
                ind++;
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = temp->next;
            free(temp);

            return head;
        }
    }
}

// function to delete before the given value
struct node *deleteBefore(struct node *head, int val)
{
}

// function to delete after the given value
struct node *deleteAfter(struct node *head, int val)
{
}
