#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// defining structure of node in a DLL
struct node{
    int data;
    struct node *prev;
    struct node *next;
};


// function to insert element at the end of DLL
struct node *insertEnd(struct node *head, int ele) {
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));

    ptr = head;

    newNode->data = ele;
    newNode->next = NULL;

    if( head == NULL) {
        head= newNode;
        return head;
    }
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
        return head;
    }

}


//function to print element of linked list
void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if(head == NULL)
        printf("\n UNDERFLOW!");

    else {
        printf("\t");
        while (ptr != NULL) {
            printf(" %d  ", ptr->data);
            if (ptr->next != NULL) {
                printf("->");
            }
            ptr = ptr->next;
        }
    }

}



// function to delete element from the end of SLL
struct node *delete_End(struct node *head) {
    struct node *ptr, *temp;
    ptr=head;
    temp=head;

    if(head == NULL) {
        printf("SLL is empty!(Underflow!!)");
        return head;
    }
    else if(ptr->next == NULL) {
        ptr=NULL;
        head=ptr;
        free(ptr);
        return head;

    }
    else {
        while(ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);

        return head;
    }

}



// main function
int main() {
    struct node *head;
    head = NULL;

    int choice, ele;
    do {
        printf("\n\n ****----- MENU -----****");
        printf("\n 1. INSERT (at End)");
        printf("\n 2. DELETE (from End)");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT\n");
        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter the number to Insert at the end of DLL :");
                scanf("%d", &ele);
                head = insertEnd(head, ele);
                printf("\n Insertion done !");
                break;

            case 2:
                head = delete_End(head);
                printf("\n Deletion done !");
                break;

            case 3:
                printf("\n Elements of SLL are : \n");
                display(head);
                break;

            case 4:
                exit(0);

        }

    } while( choice != 4);

    return 0;

}
