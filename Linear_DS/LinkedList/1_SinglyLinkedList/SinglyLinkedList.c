#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *dup = NULL;
            
// Case 1
void addNode(int data)
{
    struct node *tmp; // tmp = new node
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        last = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

// Case 2
void display()
{
    struct node *ptr = head;
    // Use the ptr pointer directly for traversal
    while (ptr != NULL)
    {
        printf(" %d -> ", ptr->data);
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

    // jis node par insert karna hai uske pehle vale node par aayenge is condition se
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
    p->next = ptr;
    ptr->next = NULL;

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
        // ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->next = p->next;
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
    free(ptr);
    return head;
}

// Case 9
struct node *DeleteAtIndex(int index)
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
    p->next = NULL;
    free(q);
    return head;
}

// Case 11
struct node *deleteValue(int source)
{
    // Check if the list is empty
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
        if (p == head)
        {
            deleteAtHead();
        }
        else if (p->next == NULL)
        {
            deleteAtEnd();
        }
        else
        {
            q->next = p->next;
            free(p);
        }
    }
    else
    {
        printf("source not found");
    }

    return head;
}

// Case 12
void findMaxMin()
{
    // Check if the list is empty
    if (head == NULL)
    {
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
    if (head == NULL || head->next == NULL)
    {
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
    if (head == NULL || head->next == NULL)
    {
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
        prev = current;       // 1
        current = next;       // 2
    }
    head = prev;
}

// Case 15
int size()
{
    int SIZE = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        SIZE++;
        ptr = ptr->next;
    }
    return SIZE;
}

struct node *rotate(int k, int SIZE)
{
    // Check if the list is empty
    if (SIZE == 0 || head == NULL)
    {
        printf("List is empty. Cannot rotate an empty list.\n");
        return head;
    }

    int loop = k % SIZE;
    loop = SIZE - loop;

    if (SIZE == 1 || loop == SIZE)
    {
        printf("List has only one node or rotate is equal to list size. No need to rotate.\n");
        return head;
    }

    struct node *temp = head;
    struct node *firstAddress = head;
    int j = 0;

    while (temp != NULL)
    {
        j++;
        if (j == loop)
        {
            firstAddress = temp->next;
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
    temp = firstAddress;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;

    return firstAddress;
}

// Case 16
struct node *swapPair()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty. Cannot swap an empty list.\n");
        return head;
    }

    int temp;
    struct node *p = head;
    struct node *q = p->next;

    while (p != NULL && q->next != NULL)
    {
        if (p->next == NULL)
        {
            break;
        }
        q = p->next;
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = q->next;
    }

    return head;
}

// Case 17
struct node *copyList(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = head->data;
        ptr->next = copyList(head->next);
        return ptr;
    }
}

int main()
{
    int choice, data, index, source;
    int k;

    while (1)
    {
        printf("\n=========================================");
        printf("\n      Simple LinkedList Operations");
        printf("\n=========================================");
        printf("\n 1. create the SLL");
        printf("\n 2. DISPLAY the SLL");
        printf("\n 3. Search an element");
        printf("\n 4. InsertAtHead");
        printf("\n 5. InsertInIndex");
        printf("\n 6. InsertAtEnd");
        printf("\n 7. InsertAfterValue");
        printf("\n 8. DeleteAtHead");
        printf("\n 9. DeleteInIndex");
        printf("\n 10. DeleteAtEnd");
        printf("\n 11. DeleteValue");
        printf("\n 12. Max and Min of SLL");
        printf("\n 13. Sort the SLL");
        printf("\n 14. Reverse the SLL");
        printf("\n 15. Rotate the SLL");
        printf("\n 16. Swap nodes in pair");
        printf("\n 17. Copy List");
        printf("\n 18. EXIT");
        printf("\n=========================================");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the no : ");
            scanf("%d", &data);
            addNode(data);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\nEnter data to search : ");
            scanf("%d", &data);
            search(data);
            break;

        case 4:
            printf("\nEnter data to insert : ");
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

            // problem => insertAtIndex function call data not entered in 0 index position(head position)
            head = InsertAtIndex(index, data);

            printf("\nAfter InsertAtIndex :");
            display();
            break;

        case 6:
            printf("\nEnter data to insert : ");
            scanf("%d", &data);

            printf("\nBefore insertAtEnd :");
            display();

            last = insertAtEnd(data);

            printf("\nAfter insertAtEnd :");
            display();
            break;

        case 7:
            printf("\nEnter the source : ");
            scanf("%d", &source);

            printf("\nEnter data to insert : ");
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

            head = DeleteAtIndex(index);

            printf("\nAfter DeleteAtIndex :");
            display();
            break;

        case 10:
            printf("\nBefore DeleteAtEnd :");
            display();

            head = deleteAtEnd();

            printf("\nAfter DeleteAtEnd :");
            display();
            break;

        case 11:
            printf("\nEnter the source : ");
            scanf("%d", &source);

            printf("\nBefore DeleteAfterValue :");
            display();

            head = deleteValue(source);

            printf("\nAfter DeleteAfterValue :");
            display();
            break;

        case 12:
            printf("\nBefore Max and Min : ");
            display();

            findMaxMin();

            break;

        case 13:
            printf("\nBefore Sort : ");
            display();

            sort();

            printf("\nAfter Sort : ");
            display();
            break;

        case 14:
            printf("\nBefore Reverse : ");
            display();

            reverse();

            printf("\nAfter Reverse : ");
            display();
            break;

        case 15:
            printf("\nEnter the No of Rotate u want : ");
            scanf("%d", &k);

            printf("\nBefore Rotate : ");
            display();

            head = rotate(k, size());

            printf("\nAfter Rotate : ");
            display();
            break;

        case 16:
            printf("\nBefore Swap nodes in Pair : ");
            display();

            head = swapPair();

            printf("\nAfter Swap nodes in Pair : ");
            display();
            break;

        case 17:
            dup = copyList(head);
            while (dup != NULL)
            {
                printf(" %d -> ", dup->data);
                dup = dup->next;
            }
            printf("NULL\n");
            break;

        case 18:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}