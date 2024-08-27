#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *AddNode(int no)
{
    // Allocate memory in the heap
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = no;
        head->next = NULL;
        last = head;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = no;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return head;
}

int main()
{
    struct node *head = NULL;

    head = AddNode(10);
    head = AddNode(20);
    head = AddNode(30);
    head = AddNode(40);
    head = AddNode(50);

    printf("%d -> ", head->data);
    printf("%d -> ", head->next->data);
    printf("%d -> ", head->next->next->data);
    printf("%d -> ", head->next->next->next->data);
    printf("%d -> NULL", last->data);

    return 0;
}