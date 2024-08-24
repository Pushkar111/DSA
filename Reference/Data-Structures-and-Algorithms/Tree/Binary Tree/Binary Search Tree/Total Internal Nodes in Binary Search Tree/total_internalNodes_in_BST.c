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



// function to find Total Internal Nodes in BST / Binary Tree
int totalInternalNodes(struct node *root)
{
    if( root==NULL || ( root->left == NULL && root->right == NULL ) ) {
        return 0;
    }
    else {
        return totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1;
    }
}
