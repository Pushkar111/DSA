// program for finding the sum of all elements in Binary Tree

#include <stdio.h>
#include <stdlib.h>



// defining the structure of Binary Tree Node
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for finding the sum of all elements in Binary Tree
int Add(struct node *root)
{
    if (root == NULL) {
        return 0;
    }
    else {
        return (root->data + Add(root->left) + Add(root->right));
    }
}
