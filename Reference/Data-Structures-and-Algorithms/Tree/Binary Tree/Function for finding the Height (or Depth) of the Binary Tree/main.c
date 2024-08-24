// program for finding the height (or depth) of the binary tree


#include <stdio.h>
#include <stdlib.h>


// declaring node of Binary-Tree
struct node {
    struct node *left;
    int data;
    struct node *right;
};



// function for finding the height (or depth) of the binary tree
int height_of_BinaryTree(struct node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL) {
        return 0;
    }
    else {
        // compute the depth of each sub-tree
        leftHeight = height_of_BinaryTree(root->left);
        rightHeight = height_of_BinaryTree(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight+1;
        }
        else {
            return rightHeight+1;
        }
    }
}
