// program for Deletion of entire Binary Tree

#include <stdio.h>
#include <stdlib.h>



// defining the structure of Binary Tree Node
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for deleting Binary Tree
// Recursive Approach
void delete_BinaryTree(struct node *root)
{
    if (root == NULL) {
        printf("\n Tree is already Empty!");
    }
    else {
        delete_BinaryTree(root->left);
        delete_BinaryTree(root->right);
        free(root);
    }
}
