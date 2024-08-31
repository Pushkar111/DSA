#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;

int main(){

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