#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// defining structure of node of BST (Binary Search Tree)
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for Finding element in BST
// Recursive Approach
struct node *search(struct node *root, int val) {
    if(root == NULL) {
        return root;
    }
    else {
        if (val < root->data) {
            return (find(root->left, val));
        }
        else if(val > root->info) {
            return ( find (root->right, val) );
        }
        else {
            return root;
        }
    }
}
