#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// defining structure of node of BST (Binary Search Tree)
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function to search an element in BST
// Iterative Approach
struct BSTNode *search(struct node *root, int val) //Non recursive version
{
    if(root == NULL)
        return NULL;

    while ( root )
    {
        if (root->info == val)
            return root; // Element node address
        else if(root->info > val)
            root = root->left;
        else
            root = root->right;
    }

    return NULL; // if element not found

}
