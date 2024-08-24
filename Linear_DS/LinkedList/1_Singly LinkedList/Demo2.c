#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *last = NULL;

void AddNode(struct node *head, int no)
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
}

int main()
{
    struct node *head = NULL;
    
    AddNode(head, 10);
    AddNode(head, 20);
    AddNode(head, 30);
    AddNode(head, 40);
    AddNode(head, 50);

    printf("%d", head->data);
    printf("%d", head->next->data);
    printf("%d", head->next->next->data);
    printf("%d", head->next->next->next->data);
    printf("%d", last->data);

    return 0;
}