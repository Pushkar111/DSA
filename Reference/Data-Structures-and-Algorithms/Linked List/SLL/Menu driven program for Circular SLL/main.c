#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the Node
struct Node {
    int data;
    struct Node *next;
};


// Print the ll
void print(struct Node *head) {
    struct Node *tortoise = head, *hare = head;
    printf("\n");
    if (head == NULL) {
        printf("Linked List is Empty");
    }
    while (hare != NULL && hare->next != NULL) {
        printf("%d -> ", tortoise->data);
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            printf("%d ", tortoise->data);
            printf("\nFound Cycle");
            return;
        }
    }
    printf("/");
}


// Count the nodes in the ll
int count(struct Node *head) {
    int numNodes = 0;
    struct Node *tortoise = head, *hare = head;
    if (head == NULL) {
        return 0;
    }
    while (hare != NULL && hare->next != NULL) {
        numNodes++;
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            return numNodes;
        }
    }
    printf("/");

    return numNodes;
}


// Insert at the head
struct Node *insertHead(struct Node *head, int ele) {
    struct Node *newNode, *headRef, *prev, *temp;
    headRef = (struct Node *)malloc(sizeof(struct Node));
    prev = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    headRef = head;
    prev = head;

    // if ll is empty it will not have any tail so to skip the process
    if (head != NULL && head->next != NULL){
        temp = head->next;
    }
    else {
        temp = head;
    }

    // Getting tail
    while (headRef != temp) {
        prev = temp;
        temp = temp->next;
    }

    // Insert at the head
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->next = head;
    head = newNode;

    // If the head was NULL, link the new Node with itself
    if (headRef == NULL) {
        newNode->next = head;
        return head;
    }

    // If the tail exists, link that to head
    prev->next = head;
    return head;
}



// Insert at Tail
struct Node *insertTail(struct Node *head, int ele){
    struct Node *newNode, *headRef, *prev, *temp;
    headRef = (struct Node *)malloc(sizeof(struct Node));
    prev = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    headRef = head;
    prev = head;

    if (head == NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode = insertHead(head, ele);
        return newNode;
    }

    // if ll is empty it will not have any tail so to skip the process
    if (head != NULL && head->next != NULL){
        temp = head->next;
    }
    else {
        temp = head;
    }

    // Getting tail
    while (headRef != temp) {
        prev = temp;
        temp = temp->next;
    }

    // Insert at the head
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->next = head;
    prev->next = newNode;

    return head;
}



// Insert at an Index
struct Node *insertAtIndex(struct Node *head, int ele, int ind) {
    int length, c = 0;
    length = count(head);
    struct Node *newNode, *headRef, *prev, *temp;
    headRef = (struct Node *)malloc(sizeof(struct Node));
    prev = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    headRef = head;
    prev = head;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL || (length <= 0 || ind <= 0)) {
        newNode = insertHead(head, ele);
        return newNode;
    } else if (length < ind) {
        newNode = insertTail(head, ele);
        return newNode;
    } else {
        while (c < ind) {
            prev = head;
            head = head->next;
            c += 1;
        }
        newNode->data = ele;
        newNode->next = head;
        prev->next = newNode;
    }
    return headRef;
}



// Delete the element from the given index
struct Node *deleteAtIndex(struct Node *head, int ind) {
    int length = count(head), it = 0, result;
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
    prev = head;
    struct Node *headRef = (struct Node *)malloc(sizeof(struct Node));
    headRef = head;

    // If index is less than 0
    if (head == NULL || ind < 0) {
        printf("Invalid Index");
        return head;
    }

    // For deleting head
    // We need to change the link from tail to next head
    if (ind == 0) {
        prev = head;
        while (head->next != prev) {
            head = head->next;
        }
        head->next = prev->next;
        printf("Deleted number is %d", prev->data);
        prev->next = NULL;
        head = head->next;
        return head;
    }

    // For deleting any node other than head
    while (it < length && head != NULL) {
        if (it == ind) {
            prev->next = head->next;
            printf("The deleted element is %d", head->data);
            return headRef;
        }
        prev = head;
        head = head->next;
        it += 1;
    }

    printf("Index out of range");
    return headRef;
}


// Main Function
int main() {
    struct Node *head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    int choice, ele, ind;
    printf("=======================================\n");
    printf(" Circular Singly Linked List\n");
    printf("=======================================\n");
    while (1) {
        printf("1. Insert at Head\n2. Insert at Tail\n3. Insert at an Index\n4. Delete at an Index\n5. Print\n6. Exit\nEnter your Choice: ");
        scanf("%d", &choice);
        printf("\n-------------------------------------\n");
        if (choice == 1) {
            printf("Enter the number to be inserted at the head: ");
            scanf("%d", &ele);
            head = insertHead(head, ele);
        } else if (choice == 2) {
            printf("Enter the number to be inserted at the tail: ");
            scanf("%d", &ele);
            head = insertTail(head, ele);
        } else if (choice == 3) {
            printf("Enter the number to be inserted at the index: ");
            scanf("%d", &ele);
            printf("Enter the index: ");
            scanf("%d", &ind);
            head = insertAtIndex(head, ele, ind);
        } else if (choice == 4) {
            printf("Enter the index to be deleted : ");
            scanf("%d", &ind);
            printf("\n");
            head = deleteAtIndex(head, ind);
            printf("\n");
        } else if (choice == 5) {
            print(head);
        }
        else {
            break;
        }
        print(head);
        printf("\n-------------------------------------\n");
    }
    return 0;
}




