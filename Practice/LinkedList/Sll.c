#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *InsertAtHead(struct node *head, int data)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));

        ptr->data = data;
        ptr->next = head;
        head = ptr;
    }

    return head;
}

struct node *InsertAtEnd(struct node *head, int data)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        ptr->data = data;
        ptr->next = NULL;
        p->next = ptr;
    }

    return head;
}

struct node *InsertAtOrder(struct node *head, int data)
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
    struct node *p = head;
    while (p->next != NULL && p->next->data < data)
    {
        p = p->next;
    }

    // Insert the new node at the correct position
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node *delete(struct node *head, int source)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }

    struct node *p = head;
    struct node *q = head;
    int flag = 0;

    while (p != NULL)
    {
        if (p->data == source)
        {
            flag = 1;
            break;
        }
        q = p;
        p = p->next;
    }

    if (flag)
    {
        if (p == head) // DeleteAtHead
        {
            head = p->next;
            free(p);
        }
        else if (p->next == NULL) // DeleteAtEnd
        {
            q->next = NULL;
            free(p);
        }
        else
        {
            q->next = p->next;
            free(p);
        }
        printf("Node with data %d deleted.\n", source);
    }
    else
    {
        printf("Source not found.\n");
    }

    return head;
}

void display(struct node *head)
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
    struct node *head = NULL;
    int data, source;
    int choice;

    while (1)
    {
        printf("\n=========================================");
        printf("\n      Simple LinkedList Operations");
        printf("\n=========================================");
        printf("\n1. InsertAtHead");
        printf("\n2. InsertAtEnd");
        printf("\n3. InsertAtOrder");
        printf("\n4. Delete");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\n=========================================");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &data);
            head = InsertAtHead(head, data);
            break;

        case 2:
            printf("Enter the data : ");
            scanf("%d", &data);
            head = InsertAtEnd(head, data);
            break;

        case 3:
            printf("Enter the data : ");
            scanf("%d", &data);
            head = InsertAtOrder(head, data);
            break;

        case 4:
            printf("Enter the source : ");
            scanf("%d", &source);
            head = delete (head, source);
            break;

        case 5:
            display(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }
}