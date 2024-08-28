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

// Case 1
void addNode(int data)
{
    struct node *temp;

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
}

// Case 2
void display()
{
    struct node *ptr = head;

    printf("  NULL <-> ");
    // Use the ptr pointer directly for traversal
    while (ptr != NULL)
    {
        printf(" %d <-> ", ptr->data);
        ptr = ptr->next; // Move to the next node
    }
    printf("NULL\n");
}

// Case 3
void search(int data)
{
    int flag = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            flag = 1;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    if (flag)
    {
        printf("Element %d Found in the list", data);
    }
    else
    {
        printf("Element %d not Found in the list", data);
    }
}

// Case 4
struct node *insertAtHead(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    if (head != NULL)
    {
        head->prev = ptr;
    }
    head = ptr;

    return head;
}

// Case 5
struct node *InsertAtIndex(int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    if (index == 0)
    {
        insertAtHead(data);
    }

    while (i != index - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            printf("Index out of bounds\n");
            return head;
        }
    }
    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != NULL)
    {
        p->next->prev = ptr;
    }
    p->next = ptr;

    return head;
}

// Case 6
struct node *insertAtEnd(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;
    last = ptr;

    return head;
}

// Case 7
struct node *insertAfterValue(int source, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p != NULL)
    {
        if (p->data == source)
        {
            break;
        }
        p = p->next;
    }

    if (p != NULL)
    {
        ptr->data = data;
        ptr->next = p->next;
        ptr->prev = p;
        if (p->next != NULL)
        {
            p->next->prev = ptr;
        }
        p->next = ptr;

        return head;
    }
    else
    {
        printf("source not found");
        return NULL;
    }
}

// Case 8
struct node *deleteAtHead()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }

    // Check if the list has only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

// Case 9
struct node *deleteAtIndex(int index)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }

    // Check if the list has only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    int i = 0;

    if (index == 0)
    {
        deleteAtHead();
    }

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
        if (q == NULL)
        {
            printf("Index out of bounds\n");
            return head;
        }
    }

    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prev = p;
    }
    free(q);
    return head;
}

// Case 10
struct node *deleteAtEnd()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }

    // Check if the list has only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    // Update the prev pointer of the node before the last node to NULL
    p->next = NULL;
    q->prev = NULL;

    free(q);
    return head;
}

// Case 11
struct node *deleteAfterValue(int source)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    while (p != NULL && q != NULL)
    {
        if (p->data == source)
        {
            break;
        }
        p = p->next;
        q = q->next;
    }

    if (p != NULL && q != NULL)
    {
        // Update the next pointer of the node before the node to be deleted
        p->next = q->next;

        // Update the prev pointer of the node after the node to be deleted
        if (q->next != NULL)
        {
            q->next->prev = p;
        }

        free(q);
    }
    else
    {
        printf("Source not found\n");
    }

    return head;
}

// Case 12
void findMaxMin()
{
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty. Cannot find max and min.\n");
        return;
    }

    struct node *ptr = head;
    int min = ptr->data;
    int max = ptr->data;

    while (ptr != NULL)
    {
        if (ptr->data < min)
        {
            min = ptr->data;
        }
        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }

    printf("\nMax : %d", max);
    printf("\nMin : %d", min);
}

// Case 13
void sort()
{
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. No need to sort.\n");
        return;
    }

    // Sort the list
    struct node *ptr = head;
    struct node *nextNode = NULL;

    while (ptr != NULL)
    {
        nextNode = ptr->next;
        while (nextNode != NULL)
        {
            if (ptr->data > nextNode->data)
            {
                int temp = ptr->data;
                ptr->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        ptr = ptr->next;
    }
}

// Case 14
void reverse()
{
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. No need to reverse.\n");
        return;
    }

    // Reverse the list    
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // 3
        current->next = prev; // 4
        current->prev = next; // Update prev pointer for doubly linked list
        prev = current;       // 1
        current = next;       // 2
    }
    head = prev;
}

int main()
{
    int choice, data, index, source;

    while (1)
    {
        printf("\n=========================================");
        printf("\n      Doubly LinkedList Operations");
        printf("\n=========================================");
        printf("\n 1. create the DLL");
        printf("\n 2. DISPLAY the DLL");
        printf("\n 3. Search an element");
        printf("\n 4. InsertAtHead");
        printf("\n 5. InsertInIndex");
        printf("\n 6. InsertAtEnd");
        printf("\n 7. InsertAfterValue");
        printf("\n 8. DeleteAtHead");
        printf("\n 9. DeleteInIndex");
        printf("\n 10. DeleteAtEnd");
        printf("\n 11. DeleteAfterValue");
        printf("\n 12. Max and Min of SLL");
        printf("\n 13. Sort the SLL");
        printf("\n 14. Reverse the SLL");
        printf("\n 15. EXIT");
        printf("\n=========================================");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &data);
            addNode(data);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Enter the data u want to search : ");
            scanf("%d", &data);
            search(data);
            break;

        case 4:
            printf("Enter the data : ");
            scanf("%d", &data);

            printf("\nBefore InsertAtHead :");
            display();

            head = insertAtHead(data);

            printf("\nAfter InsertAtHead :");
            display();
            break;

        case 5:
            printf("\nEnter position to insert : ");
            scanf("%d", &index);
            printf("\nEnter data to insert : ");
            scanf("%d", &data);

            printf("\nBefore InsertAtIndex :");
            display();

            head = InsertAtIndex(index, data);

            printf("\nAfter InsertAtIndex :");
            display();
            break;

        case 6:
            printf("Enter the data : ");
            scanf("%d", &data);

            printf("\nBefore InsertAtEnd :");
            display();

            last = insertAtEnd(data);

            printf("\nAfter InsertAtEnd :");
            display();
            break;

        case 7:
            printf("Enter the source : ");
            scanf("%d", &source);
            printf("Enter the data : ");
            scanf("%d", &data);

            printf("\nBefore InsertAfterValue :");
            display();

            struct node *newHead = insertAfterValue(source, data);
            if (newHead != NULL)
            {
                head = newHead;
            }

            printf("\nAfter InsertAfterValue :");
            display();
            break;

        case 8:
            printf("\nBefore DeleteAtHead :");
            display();

            head = deleteAtHead();

            printf("\nAfter DeleteAtHead :");
            display();
            break;

        case 9:
            printf("\nEnter position to delete : ");
            scanf("%d", &index);

            printf("\nBefore DeleteAtIndex :");
            display();

            head = deleteAtIndex(index);

            printf("\nAfter DeleteAtIndex : ");
            display();
            break;

        case 10:
            printf("\nBefore DeleteAtEnd :");
            display();

            head = deleteAtEnd();

            printf("\nAfter DeleteAtEnd : ");
            display();
            break;

        case 11:
            break;

        case 12:
            break;

        case 13:
            break;

        case 14:
            break;

        case 15:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}