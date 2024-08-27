#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node *newnode, *temp;
struct node *ptr;

void read(int n)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        newnode->prev = 0;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void display()
{
    ptr = head;
    if (head == 0)
    {
        printf("Linked List is Empty.");
        exit(0);
    }
    while (ptr != 0)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void search(int element)
{
    ptr = head;
    int pos = 1;
    if (head == 0)
    {
        printf("LInked List is Empty.");
        exit(0);
    }
    while (ptr != 0)
    {
        if (element == ptr->data)
        {
            printf("Element Found at position:%d", pos);
            return;
        }
        ptr = ptr->next;
        pos = pos + 1;
    }
    printf("Element Not found in the Linked list");
}
void insertfirst(int element)
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = 0;
    newnode->data = element;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertend(int element)
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = 0;
    while (ptr->next != 0)
    {
        ptr = ptr->next;
    }
    newnode->prev = ptr;
    ptr->next = newnode;
}
void insertafternode(int element, int item)
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    while (ptr != 0)
    {
        if (ptr->data == item)
        {
            newnode->next = ptr->next;
            ptr->next->prev = newnode;
            newnode->prev = ptr;
            ptr->next = newnode;
        }
        ptr = ptr->next;
    }
}
void insertbeforenode(int element, int item)
{
    ptr = head;
    if (head->data == item)
        insertfirst(element);
    else
    {
        while (ptr->next != 0)
        {
            if (ptr->next->data == item)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = element;
                newnode->next = ptr->next;
                ptr->next->prev = newnode;
                ptr->next = newnode;
                newnode->prev = ptr;
                return;
            }
            ptr = ptr->next;
        }
        printf("Node with data %d not found in the Linked list\n", item);
    }
}
void insertatposition(int element, int position)
{
    if (position == 1)
    {
        insertfirst(element);
    }
    else
    {
        int pos = 1;
        ptr = head;
        while (ptr != 0)
        {
            if (pos == position)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = element;
                newnode->next = ptr;
                newnode->prev = ptr->prev;
                ptr->prev->next = newnode;
                ptr->prev = newnode;
                return;
            }
            ptr = ptr->next;
            pos++;
        }
    }
}
void deletefirst()
{
    ptr = head;
    head = ptr->next;
    head->prev = 0;
    printf("The Deleted Element is:%d", ptr->data);
    free(ptr);
}
void deleteend()
{
    ptr = head;
    if (head->next == 0)
        deletefirst();
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = 0;
        printf("The Deleted Element is:%d", ptr->data);
        free(ptr);
    }
}
void deleteafternode(int item)
{
    ptr = head;
    while (ptr->next != 0)
    {
        if (ptr->data == item)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            printf("The Deleted Element is:%d", temp->data);
            free(temp);
            return;
        }
        ptr = ptr->next;
    }
    printf("Node with data %d not found in the Linked list\n", item);
}
void deletebeforenode(int item)
{
    ptr = head;
    if (head->next != NULL && head->next->data == item)
        deletefirst();
    else if (head->data == item)
        printf("Deleting is not Possible.");
    else
    {
        while (ptr->next != 0)
        {
            if (ptr->next->data == item)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                printf("The Deleted Element is:%d", ptr->data);
                free(ptr);
                return;
            }
            ptr = ptr->next;
        }
        printf("Node with data %d not found in the Linked list\n", item);
    }
}
void deleteatposition(int position)
{
    if (position == 1)
    {
        deletefirst();
    }
    else
    {
        int pos = 1;
        ptr = head;
        while (ptr != 0)
        {
            if (pos == position)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                printf("The Deleted Element is:%d", ptr->data);
                free(ptr);
                return;
            }
            ptr = ptr->next;
            pos++;
        }
    }
}
void deletespecifiednode(int item)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->data == item)
    {
        deletefirst();
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                if (ptr->next != NULL)
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                else
                {
                    ptr->prev->next = NULL;
                }

                printf("The Deleted Element is:%d\n", ptr->data);
                free(ptr);
                return;
            }
            ptr = ptr->next;
        }

        printf("Element %d not found in the list.\n", item);
    }
}
int main()
{
    int choice;
    int n, c, item, pos;
    do
    {
        printf("Enter Elements:");
        scanf("%d", &n);
        read(n);
        printf("Do you Want to continue(0 0r 1):");
        scanf("%d", &c);
    } while (c);
    do
    {
        printf("\n1.Display");
        printf("\n2.Search");

        printf("\n\n***INSERTION***\n");
        printf("\n3.Insert First");
        printf("\n4.Insert at End");
        printf("\n5.Insert After Node");
        printf("\n6.Insert Before Node");
        printf("\n7.Insert at Position");

        printf("\n\n***DELETION***\n");
        printf("\n8.Delete at First");
        printf("\n9.Delete at End");
        printf("\n10.Delete After Node");
        printf("\n11.Delete Before Node");
        printf("\n12.Delete at Position");
        printf("\n13.Delete Specified Node");

        printf("\n14.Exit");
        printf("\nEnter Choice to Perform Action:");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("Enter Element to Search:");
            scanf("%d", &n);
            search(n);
            break;
        case 3:
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertfirst(n);
            break;
        case 4:
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertend(n);
            break;
        case 5:
            printf("Enter Node:");
            scanf("%d", &item);
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertafternode(n, item);
            break;
        case 6:
            printf("Enter Node:");
            scanf("%d", &item);
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertbeforenode(n, item);
            break;
        case 7:
            printf("Enter position:");
            scanf("%d", &pos);
            printf("Enter Element to Insert:");
            scanf("%d", &n);
            insertatposition(n, pos);
            break;
        case 8:
            deletefirst();
            break;
        case 9:
            deleteend();
            break;
        case 10:
            printf("Enter Node:");
            scanf("%d", &item);
            deleteafternode(item);
            break;
        case 11:
            printf("Enter Node:");
            scanf("%d", &item);
            deletebeforenode(item);
            break;
        case 12:
            printf("Enter position:");
            scanf("%d", &pos);
            deleteatposition(pos);
            break;
        case 13:
            printf("Enter Node to delete:");
            scanf("%d", &item);
            deletespecifiednode(item);
            break;
        case 14:
            exit(0);

        default:
            printf("\nEnter Correct Choice.");
            break;
        }
    } while (1);
}
