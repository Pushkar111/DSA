// program to create a linked list
// and perform insertions and deletions of all cases.

// Write functions to sort and finally delete the entire list at once.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// defining the structure of node in SLL
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// function to insert element at the end of linked list
struct node *insert_End(struct node *head, int ele)
{
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    newNode->data = ele;
    newNode->next = NULL;

    if (ptr == NULL)
    {
        ptr = newNode;
        head = ptr;
    }
    else if (ptr->next == NULL)
    {
        ptr->next = newNode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

// function to print element of linked list
void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("\n SLL is empty!");
    else
    {
        while (ptr != NULL)
        {
            printf("  %d ", ptr->data);
            if (ptr->next != NULL)
            {
                printf("->");
            }
            ptr = ptr->next;
        }
    }
}

// function to insert at the beginning of linked list
struct node *insert_Beg(struct node *head, int ele)
{
    struct node *newNode, *ptr;
    ptr = head;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = ele;
    newNode->next = ptr;
    head = newNode;

    return head;
}

// function to insert before the given element
struct node *insert_Before(struct node *head, int val, int ele)
{
    struct node *newNode, *ptr, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    newNode->data = ele;

    // when element is to be inserted before first element
    if (ptr->data == val)
    {
        head = insert_Beg(head, ele);
    }
    // when we want to insert at any place instead of beginning
    else
    {
        while (ptr->data != val)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = newNode;
        newNode->next = ptr;
    }
    return head;
}

struct node *insert_After(struct node *head, int val, int ele)
{
    struct node *newNode, *ptr, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    temp = ptr;
    newNode->data = ele;

    if (ptr->data == val)
    {
        head = insert_End(head, ele);
    }
    else
    {
        while (temp->data != val)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = newNode;
        newNode->next = ptr;
    }
    return head;
}

// function to delete first node of SLL
struct node *delete_Beg(struct node *head)
{
    struct node *ptr;
    ptr = head; // so that we can free the initial space occupied by head later

    if (head == NULL)
    {
        printf("SLLis empty!");
        return head;
    }
    else
    {
        head = head->next;
        free(ptr);
        return head;
    }
}

// function to delete Node from the end of SLL
struct node *delete_End(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = head;

    if (head == NULL)
    {
        printf("SLL is empty!(UNDERFLOW)");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
    return head;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
struct node *delete_node(struct node *head, int val)
{
    struct node *curr = head;
    struct node *prev = NULL;
    if (curr->data == val)
    {
        head = curr->next;
        return head;
    }
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == val)
            break;
    }
    prev->next = curr->next;
    free(curr);
    free(prev);

    return head;
}

// function to delete entire SLL
struct node *deleteSLL(struct node *head)
{
    struct node *ptr, *temp;
    temp = head;

    while (temp != NULL)
    {
        ptr = temp->next;
        temp = ptr;
    }
    head = temp;
    free(temp);
    return head;
}

// function to delete before the given value
struct node *delete_Before(struct node *head, int val)
{
}

// function to delete after the given value
struct node *delete_After(struct node *head, int val)
{
}

// function for sorting SLL ( INSERTION SORT )
struct node *sortSLL(struct node *head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    if (head == NULL)
    {
        printf("\n SLL is EMPTY!");
    }
    else
    {
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while (ptr2 != NULL)
            {
                if (ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    return head; // Had to be added
}

struct node *reverseSLL(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    if (head == NULL)
    {
        printf("\n SLL is EMPTY!!");
    }

    else
    {
        while (curr != NULL)
        {
            next = curr->next; // Store next

            // Reverse current node's pointer
            curr->next = prev;

            // Move pointers one position ahead.
            prev = curr;
            curr = next;
        }
        head = prev;
        printf("\n SLL is REVERSED!");
    }

    return head;
}

// main function
int main()
{
    int option, ele, val;
    do
    {
        printf("\n\n *****---- MAIN MENU ----*****");
        printf("\n 1: CREATE a SLL(By inserting at End)");
        printf("\n 2: DISPLAY the SLL");
        printf("\n 3: ADD a node at the beginning");
        printf("\n 4: ADD a node at the end");
        printf("\n 5: ADD a node before a given node");
        printf("\n 6: ADD a node after a given node");
        printf("\n 7: DELETE a node from the beginning");
        printf("\n 8: DELETE a node from the end");
        printf("\n 9: DELETE a given node");
        printf("\n 10: DELETE a node before a given node");
        printf("\n 11: DELETE a node after a given node");
        printf("\n 12: DELETE the entire list");
        printf("\n 13: SORT the list");
        printf("\n 14: REVERSE SLL");
        printf("\n 15: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to Insert at the end of SLL(To CREATE SLL) :");
            scanf("%d", &ele);
            head = insert_End(head, ele);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            printf("\n The SLL is : \n");
            display(head);
            break;
        case 3:
            printf("Enter the elements to INSERT at beginning of SLL:");
            scanf("%d", &ele);
            head = insert_Beg(head, ele);
            break;
        case 4:
            printf("Enter the elements to INSERT at End of SLL:");
            scanf("%d", &ele);
            head = insert_End(head, ele);
            break;
        case 5:
            printf("\n Enter the value before which the data has to be inserted : ");
            scanf("%d", &val);
            printf("\n Enter the element to INSERT : ");
            scanf("%d", &ele);
            head = insert_Before(head, val, ele);
            break;
        case 6:
            printf("\n Enter the value after which the data has to be inserted : ");
            scanf("%d", &val);
            printf("\n Enter the element to INSERT : ");
            scanf("%d", &ele);
            head = insert_After(head, val, ele);
            break;
        case 7:
            head = delete_Beg(head);
            break;
        case 8:
            head = delete_End(head);
            break;
        case 9:
            printf("\n Enter the value of the node which has to be deleted : ");
            scanf("%d", &val);
            head = delete_node(head, val);
            break;
        case 10:
            printf("\n Enter the value before which the node has to deleted : ");
            scanf("%d", &val);
            head = delete_Before(head, val);
            break;
        case 11:
            printf("\n Enter the value after which the node has to deleted : ");
            scanf("%d", &val);
            head = delete_After(head, val);
            break;
        case 12:
            head = deleteSLL(head);
            printf("\n LINKED LIST DELETED");
            break;
        case 13:
            head = sortSLL(head); // insertion sort
            break;
        case 14:
            head = reverseSLL(head);
        }
    } while (option != 15);

    return 0;
}
