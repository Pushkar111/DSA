// function for Searching in Binary Tree

#include <stdio.h>
#include <stdlib.h>



// defining the structure of Binary Tree Node
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for Searching in Binary Tree
struct node *search(struct node *root, int val)
{
    struct node *temp;
    if(root == NULL) {
        return root;
    }
    else {
        if (val == root->data) {
            return root;
        }
        else {
            temp = search(root->left, val);

            if(temp != NULL) {
                return temp;
            }
            else {
                return (search(root->right, val));
            }
        }
    }
}
