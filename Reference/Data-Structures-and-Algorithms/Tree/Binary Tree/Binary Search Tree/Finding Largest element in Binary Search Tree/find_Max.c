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




// function for finding the maximum element in a Binary Search Tree
// Recursive Approach
struct node *find_Max(struct node *root)
{
    if (root == NULL || root->right == NULL) {
        return root;
    }
    else {
        find_Max(root->right);
    }
}
