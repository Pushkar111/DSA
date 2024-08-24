// Function to Insert on the LEFT and Right of Node in Binary Tree

#include <stdio.h>
#include <malloc.h>


// declaring node of Binary-Tree
struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int info;
    struct BinaryTreeNode *right;
};


// function to create Binary Tree
/* newNode() allocates a new node with the given data and NULL left and
right pointers. */
struct BinaryTreeNode* createNode(struct BinaryTreeNode *root, int data)
{
    // Allocate memory for new node
    struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));

    // Assign data to this node
    newNode->info = data;

    // Initialize left and right children as NULL
    newNode->left = NULL;
    newNode->right = NULL;

    root = newNode;

    return root;
}


// function to Insert on the left of the node
struct BinaryTreeNode *insertLeft(struct BinaryTreeNode *root, int data) {
    root->left = createNode(root, data);
    return root->left;
}


// function to Insert on the right of the node
struct BinaryTreeNode *insertRight(struct BinaryTreeNode *root, int data) {
    root->right = createNode(root, data);
    return root->right;
}
