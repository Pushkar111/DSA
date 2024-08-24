#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// defining structure of BST Node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};



// function to find Total Nodes in BST / Binary Tree
int totalNodes(struct node *root)
{
    if(root == NULL) {
        return 0;
    }
    else {
        return (totalNodes(root->left) + totalNodes(root->right) + 1);
    }
}
