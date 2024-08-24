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




// function for Deletion in Binary Search Tree
struct node *Delete(struct node *root, int val) {

    // if tree is empty or no nodes left to search x, then declare element not found
    if (root == NULL) {
        printf("\n Element Not found !");
    }

    // if x is less than the element in r then traverse the left sub tree of r
    else if (root->data > val) {
        root->left = Delete(root->left, val);
    }

    // if x is less than the element in r then traverse the right sub tree of r
    else if (root->data < val) {
        root->right = Delete(root->right, val);
    }

    else // if element found
    {
        struct node *temp = root;

        if (root->left == NULL && root->right == NULL) { // Case-1
            return NULL;
        }
        else if (root->left == NULL) { // Case-2
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) { // Case-2
            root = root->left; free(temp);
        }
        else if( root->left && root->right) { // case-3
            temp = find_Max(root->left);
            root->data = temp->data;
            root->left = Delete (root->left, temp->data);}
        }

        return root;

}
