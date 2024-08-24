// 15. Find the Nth node from the end of the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display(struct node *);
struct node *insert_End(struct node *, int);
struct node *Find_Nth_Node(struct node *, int);

int main()
{
    int n; // n = Total number of Nodes of SLL
    int ele;
    int m; // m = number of node from end that we require to access
    struct node *newNode;
    printf("\n Enter the total number of Nodes in SLL : ");
    scanf("%d", &n);

    printf("\n Enter the elements to insert at the end of SLL : \n");
    // Use insert_End and create a list with n nodes
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        head = insert_End(head, ele);
    }
    printf("\n Entered SLL is : ");
    display(head);

    printf("\n\n Enter the position of node from the end that you require : ");
    scanf("%d", &m);

    if (m <= n && n > 0)
    {
        newNode = Find_Nth_Node(head, m);
        printf("\n The data in %d th/rd/nd node from the end is : %d", m, newNode->data);
    }
    else
    {
        printf("\n There is no nth node");
    }

    return 0;
}

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

// function for finding the Nth node from the End of SLL
// Return the address of nth node from the end of the list
struct node *Find_Nth_Node(struct node *head, int m)
{
    struct node *temp1, *temp2;
    temp1 = head;
    temp2 = head;
    if (head == NULL)
    {
        return head;
    }
    else
    {
        int count = 0;
        while (temp1 != NULL)
        {
            count++;
            temp1 = temp1->next;
        }
        int x = count - m;
        while (x > 0)
        {
            x--;
            temp2 = temp2->next;
        }
        return temp2;
    }
}
