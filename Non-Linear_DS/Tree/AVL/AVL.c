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
            }
            else
            {
                printf("\nLEFT");
            }
        }
        else
        {
            printf("\nLEFT");
            if (data < root->left->data)
            {
                printf("\nLEFT");
            }
            else
            {
                printf("\nRIGHT");
            }
        }
    }

    return root;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d(%d) ", root->data, root->height);
        inOrder(root->right);
    }
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
        root = insertNode(root, 10);
        insertNode(root, 20);
        insertNode(root, 30);
        break;

    case 2: // LL
        root = insertNode(root, 30);
        insertNode(root, 20);
        insertNode(root, 10);
        break;

    case 3: // RL
        root = insertNode(root, 10);
        insertNode(root, 30);
        insertNode(root, 20);
        break;

    case 4: // LR
        root = insertNode(root, 30);
        insertNode(root, 10);
        insertNode(root, 20);
        break;
    }

    // inOrder(root);
    return 0;
}