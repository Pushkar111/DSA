#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    node->height = 1; // Starting height from 1

    return node;
}

int findHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int max(int lh, int rh)
{
    return (lh > rh) ? lh : rh;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        int bf = findHeight(root->left) - findHeight(root->right);
        printf("%d(%d) ", root->data, bf);
        inOrder(root->right);
    }
}

struct node *leftRotate(struct node *root)
{
    struct node *newRoot = root->right;

    if (newRoot->left == NULL) // RR
    {
        root->right = newRoot->left; // root->right = NULL;
        newRoot->left = root;
    }
    else // RL
    {
        struct node *temp = newRoot->left;
        newRoot->left = root;
        root->right = temp;
    }

    root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
    newRoot->height = max(findHeight(newRoot->left), findHeight(newRoot->right)) + 1;

    return newRoot;
}

struct node *rightRotate(struct node *root)
{
    struct node *newRoot = root->left;

    if (newRoot->left == NULL) // LL
    {
        root->left = newRoot->right; // root->left = NULL;
        newRoot->right = root;
    }
    else
    {
        struct node *temp = newRoot->right;
        newRoot->right = root;
        root->left = temp;
    }

    root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
    newRoot->height = max(findHeight(newRoot->left), findHeight(newRoot->right)) + 1;

    return newRoot;
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    root->height = max(findHeight(root->left), findHeight(root->right)) + 1; // Find max height from LeftChild and RightChild , Add 1 to it
    int bf = findHeight(root->left) - findHeight(root->right);               // bf = lh - rh

    if (bf < -1 || bf > 1)
    {
        printf("\n%d --- [%d]  imbalance", root->data, bf);
        if (bf < -1)
        {
            printf("\nRIGHT");
            if (data > root->right->data)
            {
                printf("\nRIGHT");
                printf("\nBefore Rotations : ");
                inOrder(root);
                root = leftRotate(root);
            }
            else
            {
                printf("\nLEFT");
                printf("\nBefore Rotations : ");
                inOrder(root);
                root = leftRotate(root);
            }
        }
        else
        {
            printf("\nLEFT");
            if (data < root->left->data)
            {
                printf("\nLEFT");
                printf("\nBefore Rotations : ");
                inOrder(root);
                root = rightRotate(root);
            }
            else
            {
                printf("\nRIGHT");
                printf("\nBefore Rotations : ");
                inOrder(root);
                root = rightRotate(root);
            }
        }
    }

    return root;
}

int main()
{
    struct node *root = NULL;
    int choice;

    printf("=============== Check Rotations ================");
    printf("\n1. RR");
    printf("\n2. LL");
    printf("\n3. RL");
    printf("\n4. LR");
    printf("\nEnter the choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // RR

        /* Example : 1 */
        root = insertNode(root, 10);
        root = insertNode(root, 20);
        root = insertNode(root, 30);

        /* Example : 2 */
        // root = insertNode(root, 70);
        // root = insertNode(root, 40);
        // root = insertNode(root, 80);
        // root = insertNode(root, 75);
        // root = insertNode(root, 90);
        // root = insertNode(root, 100);
        break;

    case 2: // LL
        root = insertNode(root, 30);
        root = insertNode(root, 20);
        root = insertNode(root, 10);
        break;

    case 3: // RL
        root = insertNode(root, 10);
        root = insertNode(root, 30);
        root = insertNode(root, 20);
        break;

    case 4: // LR
        root = insertNode(root, 30);
        root = insertNode(root, 10);
        root = insertNode(root, 20);
        break;
    }

    printf("\nAfter Rotations : ");
    inOrder(root);
    return 0;
}