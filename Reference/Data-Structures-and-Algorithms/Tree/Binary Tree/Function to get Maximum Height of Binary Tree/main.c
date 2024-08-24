// program for getting Maximum height of the Binary Tree

#include <stdio.h>
#include <malloc.h>


// declaring node of Binary-Tree
struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int info;
    struct BinaryTreeNode *right;
};



// function to get Maximum Height of Binary Tree
// Recursive Approach
int getHeight(struct BinaryTreeNode *root) {

    int leftHeight = 0;
    int rightHeight = 0;

    if (root == NULL) {
        return -1;
    }
    if (root->left != NULL) {
        leftHeight = 1 + getHeight(root->left);
    }
    if (root->right != NULL) {
        rightHeight = 1 + getHeight(root->right);
    }

    return (leftHeight > rightHeight ? leftHeight : rightHeight);
}
