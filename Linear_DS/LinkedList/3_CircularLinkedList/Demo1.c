#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr = head;
    do {
        printf(" %d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("NULL\n");
}

int main()
{
    // Allocate memory in the Heap
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *last = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 10;
    head->next = second;

    // Link second and third nodes
    second->data = 20;
    second->next = third;

    // Link third and last node
    third->data = 30;
    third->next = last;

    // Terminate the list
    last->data = 40;
    last->next = head;

    display(head);
    return 0;
}