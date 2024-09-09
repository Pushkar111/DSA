/*

==> Properties of BST
========================================
1. The left subtree of a node contains only nodes with keys lesser than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Every node has at most two children (left and right child).
4. The left and right subtree each must also be a binary search tree.
5. The BST formed must be a Binary Search Tree.
6. There is no duplicate node in a binary search tree.
7. in-order traversal of a BST gives the nodes in sorted order.


    Let us create following BST
    1)
           5
         /  \
        3    7
      / \   / \
     2  4  6  8

    2)
           9
         /  \
        4   11
      / \    \
     2  7    15
       / \    \
      5  8    14


*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Case 1 : Create node
struct node *createNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Case 2 : Insert node
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

    return root;
}

// Case 3 : Pre-Order Traversal
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Case 4 : In-Order Traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Case 5 : Post-Order Traversal
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Case 6 : Search Node
int searchNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else if (data > root->data)
    {
        return searchNode(root->right, data);
    }
    else
    {
        return 1;
    }
}

// Case 7 : Find Min Max
int findMin(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findMax(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// Case 8 : Delete Node
struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Case 1 : node has no Children -> leaf node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root == NULL;
        }
        // Case 2 : node has one Children
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3 : node has Two Children
        else
        {
            int minValue = findMin(root->right);
            root->data = minValue;
            root->right = deleteNode(root->right, minValue);
        }
    }
    return root;
}

// Case 9 : Check BST
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        // Check the left subtree
        if (!isBST(root->left))
        {
            return 0;
        } 
        
        // Check current node: it must be greater than the previous node in in-order traversal
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        
        // Update the previous node
        prev = root;

        // Check the right subtree
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int choice;
    int data;
    int minValue, maxValue;

    struct node *root = NULL;
    while (1)
    {
        printf("\n\n========================================================================");
        printf("\n                              BST ");
        printf("\n========================================================================");
        printf("\n1. createNode");
        printf("\n2. insertNode");
        printf("\n3. pre-order Traversal");
        printf("\n4. in-order Traversal");
        printf("\n5. post-order Traversal");
        printf("\n6. searchNode");
        printf("\n7. findMinMax");
        printf("\n8. deleteNode");
        printf("\n9. isBST");
        printf("\n10. Exit");
        printf("\n========================================================================");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createNode(9);
            printf("createNode Successfully");
            break;

        case 2:
            root = insertNode(root, 4);
            root = insertNode(root, 11);
            root = insertNode(root, 2);
            root = insertNode(root, 7);
            root = insertNode(root, 15);
            root = insertNode(root, 5);
            root = insertNode(root, 8);
            root = insertNode(root, 14);
            printf("insertNode Successfully");
            break;

        case 3:
            preOrder(root);
            break;

        case 4:
            inOrder(root);
            break;

        case 5:
            postOrder(root);
            break;

        case 6:
            printf("\nEnter the data to Search : ");
            scanf("%d", &data);

            if (searchNode(root, data))
            {
                printf("%d is found", data);
            }
            else
            {
                printf("%d is not found", data);
            }
            break;

        case 7:
            minValue = findMin(root);
            maxValue = findMax(root);
            printf("\nMin Value : %d", minValue);
            printf("\nMax Value : %d", maxValue);
            break;

        case 8:
            printf("\nEnter the data to Delete : ");
            scanf("%d", &data);

            root = deleteNode(root, data);
            printf("%d is Deleted", data);
            break;

        case 9:
            if (isBST(root))
            {
                printf("Tree is BST");
            }
            else
            {
                printf("Tree is not BST");
            }
            break;

        case 10:
            exit(0);
            break;
        }
    }

    return 0;
}