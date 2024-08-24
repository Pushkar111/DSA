#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    // Allocate memory in the heap
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
    last->next = NULL;

    display(head);
    return 0;
}