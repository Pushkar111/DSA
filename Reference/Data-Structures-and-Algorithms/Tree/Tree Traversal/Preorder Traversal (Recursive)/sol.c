#include <stdio.h>
#include <malloc.h>


// declaring node of Binary-Tree
struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int info;
    struct BinaryTreeNode *right;
};


struct BinaryTreeNode *root=NULL;



// function for preOrder Traversal (Recursive Approach)
void preorderTraversal(struct BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }
    else {
        printf(" %d ", root->info);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
