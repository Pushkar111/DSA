#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *addNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
        last = head;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    return head;
}

int main()
{
    struct node *head = NULL;

    head = addNode(10);
    head = addNode(20);
    head = addNode(30);
    head = addNode(40);
    head = addNode(50);

    printf("%d -> ", head->data);
    printf("%d -> ", head->next->data);
    printf("%d -> ", head->next->next->data);
    printf("%d -> ", head->next->next->next->data);
    printf("%d -> NULL", last->data);

    return 0;
}