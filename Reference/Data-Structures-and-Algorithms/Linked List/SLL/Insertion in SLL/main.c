#include <stdio.h>
#include <stdlib.h>

// defining the structure of node in SLL
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// function to insert at the beginning of linked list
struct node *insertAtHead(struct node *head, int ele)
{
    struct node *newNode, *ptr;
    ptr = head;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = ele;
    newNode->next = ptr;
    head = newNode;

    return head;
}

// function to insert element at the end of linked list
struct node *insertAtTail(struct node *head, int ele)
{
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    newNode->data = ele;
    newNode->next = NULL;

    if (ptr == NULL)
    {
        ptr = newNode;
        head = ptr;
    }
    else if (ptr->next == NULL)
    {
        ptr->next = newNode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

// inserting element at the specified position (at any index)
struct node *insertAtIndex(struct node *head, int element, int index)
{
}

// function to insert before the given element
struct node *insertBefore(struct node *head, int val, int ele)
{
    struct node *newNode, *ptr, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    newNode->data = ele;

    // when element is to be inserted before first element
    if (ptr->data == val)
    {
        head = insertAtHead(head, ele);
    }
    // when we want to insert at any place instead of beginning
    else
    {
        while (ptr->data != val)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = newNode;
        newNode->next = ptr;
    }
    return head;
}

// function to insert after a given element
struct node *insertAfter(struct node *head, int val, int ele)
{
    struct node *newNode, *ptr, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    temp = ptr;
    newNode->data = ele;

    if (ptr->data == val)
    {
        head = insertAtTail(head, ele);
    }
    else
    {
        while (temp->data != val)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = newNode;
        newNode->next = ptr;
    }
    return head;
}