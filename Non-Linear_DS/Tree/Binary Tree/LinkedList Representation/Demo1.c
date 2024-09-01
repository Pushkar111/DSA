/*
1) root           -> Top Most node
2) node           -> Each element in Binary Tree is node
3) Parent & Child -> node considered as parent when node consists left and right child
4) Leaf           -> node which does not have any child
    ↓
  (External / Terminal) 
5) SubTree        -> set of nodes which are connected with root
6) Depth          -> Number of edges in the path from root to that node
7) Height         -> Maximum number of edges in the path from root to any leaf node
8) Sibling        -> nodes which have same parent
9) Degree         -> no of Direct children

==> Binary Tree   -> Tree of Degree 2
                    (nodes can have 0, 1, 2 children)
                  -> Ideal for representing hierarchical data
                  -> n nodes => edges ==> n-1
            
    ==> Types of Binary Trees
        ---------------------
                                Types 
                                  |
                    -------------------------------    
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

int main()
{
    struct node *leftChild, *rightChild;

    root = (struct node *)malloc(sizeof(struct node));
    root->data = 10;

    leftChild = (struct node *)malloc(sizeof(struct node));
    leftChild->data = 20;
    leftChild->left = NULL;
    leftChild->right = NULL;

    rightChild = (struct node *)malloc(sizeof(struct node));
    rightChild->data = 30;
    rightChild->left = NULL;
    rightChild->right = NULL;

    root->left = leftChild;
    root->right = rightChild;

    printf("%d  %d  %d", root->data, root->left->data, root->right->data);

    return 0;
}