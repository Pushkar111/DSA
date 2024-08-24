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



// function to find Total External Nodes in BST / Binary Tree
int totalExternalNodes(struct node *root)
{
    if(root == NULL) {
        return 0;
    }
    else if ( root->left==NULL && root->right == NULL ) {
        return 1;
    }
    else {
        return (totalExternalNodes(root->left) + totalExternalNodes(root->right));
    }
}
