#include <stdio.h>
#include <malloc.h>


// declaring node of Binary-Tree
struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int info;
    struct BinaryTreeNode *right;
};


struct BinaryTreeNode *root=NULL;



// function for inOrder Traversal (Recursive Approach)
void inorderTraversal(struct BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }
    else {
        inorderTraversal(root->left);
        printf(" %d ", root->info);
        inorderTraversal(root->right);
    }
}
