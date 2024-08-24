// program for Finding Size of Binary Tree

#include <stdio.h>
#include <stdlib.h>



// defining the structure of Binary Tree Node
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for Finding Size of Binary Tree
// Recursive Approach
int size_of_BinaryTree(struct node *root)
{
    if (root == NULL) {
        return 0;
    }
    else {
        return ( size_of_BinaryTree(root->left) + 1 + size_of_BinaryTree(root->right));
    }
}