// insertAtOrder in SLL
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *insertAtOrder(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    // Case 1: If the list is empty or the new node needs to be inserted at the head
    if (head == NULL || head->data >= data)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }

    // Case 2: Traverse the list to find the correct position for the new node
    struct node *current = head;
    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }

    // Insert the new node at the correct position
    ptr->next = current->next;
    current->next = ptr;

    return head;
}

void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    insertAtOrder(29);
    insertAtOrder(10);
    insertAtOrder(25);
    insertAtOrder(40);
    insertAtOrder(37);

    display();

    return 0;
}