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




// function for Inserting an element in Binary Search Tree
// Recursive Approach
struct node *insertElement(struct node *root, int val)
{
    if ( root == NULL) {
        root = (struct node *)malloc(sizeof(struct node)); // memory allocation for creating the newNode to store the new element
        root->data = val;
        root->left = root->right = NULL;
    }
    else if ( val < root->data  ) {
        root->left = insertElement(root->left, val);
    }
    else {
        root->right = insertElement(root->right, val);
    }

    return root;
}
