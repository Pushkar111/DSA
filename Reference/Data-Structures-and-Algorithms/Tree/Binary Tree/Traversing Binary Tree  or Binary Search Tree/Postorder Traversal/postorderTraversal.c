#include <stdio.h>
#include <malloc.h>


// declaring node of Binary-Tree
struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    int info;
    struct BinaryTreeNode *right;
};


struct BinaryTreeNode *root=NULL;



// function for postOrder Traversal (Recursive Approach)
void postorderTraversal(struct BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }
    else {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf(" %d ", root->info);
    }
}
